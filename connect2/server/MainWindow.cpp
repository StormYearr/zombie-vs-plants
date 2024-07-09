#include "MainWindow.h"
//#include "MainWindowServer.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindowServer::MainWindowServer(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *portLabel = new QLabel("Server Port:", centralWidget);
    layout->addWidget(portLabel);

    portEdit = new QLineEdit("12345", centralWidget);
    layout->addWidget(portEdit);

    startButton = new QPushButton("Start Server", centralWidget);
    layout->addWidget(startButton);
    connect(startButton, &QPushButton::clicked, this, &MainWindowServer::startServer);

    statusLabel = new QLabel("Server is not running.", centralWidget);
    layout->addWidget(statusLabel);

    messageList = new QListWidget(centralWidget);
    layout->addWidget(messageList);

    messageEdit = new QLineEdit(centralWidget);
    layout->addWidget(messageEdit);

    sendButton = new QPushButton("Send Message", centralWidget);
    layout->addWidget(sendButton);
    connect(sendButton, &QPushButton::clicked, this, &MainWindowServer::sendMessage);

    tcpServer = nullptr;

    setWindowTitle("Server");
    resize(400, 300);
}

MainWindowServer::~MainWindowServer()
{
    if (tcpServer) {
        tcpServer->close();
        delete tcpServer;
    }
}

void MainWindowServer::startServer()
{
    quint16 serverPort = portEdit->text().toUShort();

    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection, this, &MainWindowServer::newConnection);

    if (!tcpServer->listen(QHostAddress::Any, serverPort)) {
        QMessageBox::critical(this, "Error", "Unable to start the server.");
        return;
    }

    statusLabel->setText("Server started. Waiting for clients...");
    startButton->setEnabled(false);
}

void MainWindowServer::newConnection()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    clients.append(clientSocket);

    connect(clientSocket, &QTcpSocket::readyRead, this, &MainWindowServer::readData);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MainWindowServer::clientDisconnected);

    statusLabel->setText("Client connected.");
}

void MainWindowServer::readData()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket)
        return;

    QByteArray data = clientSocket->readAll();
    if (data.isEmpty())
        return;

    QString message = QString::fromUtf8(data);
    qDebug() << "Received from client:" << message;

    // Display the received message in the message list
    messageList->addItem("Client: " + message);

    // Process message based on the first character
    if (message.startsWith("Z"))
    {
        // Extract coordinates from the message
        QStringList parts = message.split(" ");
        if (parts.size() >= 3) {
            QString xCoord = parts[1];
            QString yCoord = parts[2];

            // Process coordinates as needed
            qDebug() << "Received coordinates X:" << xCoord << " Y:" << yCoord;

            // Example: Create a new Ground item (z3) based on received coordinates
//            Ground *newGround = new Ground();
//            newGround->setPos(xCoord.toDouble(), yCoord.toDouble());
//            scene->addItem(newGround);
        }
    }
    else if (message.startsWith("P"))
    {
        // Handle other types of messages starting with 'P'
        // Example: Processing for 'P' messages
    }

    // Broadcast message to all clients except sender
    for (QTcpSocket *otherClient : clients) {
        if (otherClient != clientSocket) {
            otherClient->write(data);
        }
    }
}

void MainWindowServer::clientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket)
        return;

    clients.removeOne(clientSocket);
    clientSocket->deleteLater();

    statusLabel->setText("Client disconnected.");
}

void MainWindowServer::sendMessage()
{
    QString message = messageEdit->text();
    if (message.isEmpty())
        return;

    QByteArray data = message.toUtf8();
    messageList->addItem("Server: " + message);

    // Broadcast message to all clients
    for (QTcpSocket *client : clients) {
        client->write(data);
    }

    messageEdit->clear();
}
