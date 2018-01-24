#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "mail/SmtpMime"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pb_sendEmail_clicked();
    void on_tb_getAttach1_clicked();
    void on_tb_getAttach2_clicked();
    void on_tb_getAttach3_clicked();
    void on_tb_getAttach4_clicked();

private:
    Ui::MainWindow *ui;
    QStringList getRecipientsAddress(QString str);

    int sendEmail();
};

#endif // MAINWINDOW_H
