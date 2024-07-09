#ifndef MAINWINDOWSERVER_H
#define MAINWINDOWSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

class MainWindowServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowServer(QWidget *parent = nullptr);
    ~MainWindowServer();

private slots:
    void startServer();
    void newConnection();
    void readData();
    void clientDisconnected();
    void sendMessage();

private:
    QTcpServer *tcpServer;
    QList<QTcpSocket*> clients;
    QLabel *statusLabel;
    QListWidget *messageList;
    QLineEdit *portEdit;
    QLineEdit *messageEdit; // Added for sending messages
    QPushButton *startButton;
    QPushButton *sendButton; // Button to send messages
};

#endif // MAINWINDOWSERVER_H
