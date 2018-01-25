#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_sendEmail_clicked()
{
    if(ui->le_emailUser->text() != NULL && ui->le_emailPass->text() !=NULL){
        if(ui->le_emailPort->text().toInt() != NULL && ui->le_emailSmtp->text()!=NULL){
            if(ui->le_sendersAdd->text() != NULL && ui->le_toAdd->text() != NULL){
                sendEmail();
            }else QMessageBox::information(this,"Fill info", "please input senders addres and reciever addres");
        }else QMessageBox::information(this,"Fill info", "please input port and smtp");
    }else QMessageBox::information(this,"Fill info", "please input username and password");

}

int MainWindow::sendEmail(){

    SmtpClient smtp(ui->le_emailSmtp->text(), ui->le_emailPort->text().toInt(), SmtpClient::SslConnection);

    smtp.setUser(ui->le_emailUser->text());
    smtp.setPassword(ui->le_emailPass->text());

    MimeMessage message;

    EmailAddress sender(ui->le_sendersAdd->text(), ui->le_sendersName->text());
    message.setSender(&sender);

    //create list of to
    QStringList to = getRecipientsAddress(ui->le_toAdd->text());
    QStringList cc = getRecipientsAddress(ui->le_ccAdd->text());
    QStringList bcc = getRecipientsAddress(ui->le_bccAdd->text());

    for (QStringList::iterator it = to.begin();it != to.end(); ++it) {
         message.addRecipient(new EmailAddress(*it),MimeMessage::To);
    }
    for (QStringList::iterator it = cc.begin();it != cc.end(); ++it) {
         message.addRecipient(new EmailAddress(*it),MimeMessage::Cc);
    }
    for (QStringList::iterator it = bcc.begin();it != bcc.end(); ++it) {
         message.addRecipient(new EmailAddress(*it),MimeMessage::Bcc);
    }

    //set message subject
    message.setSubject(ui->le_emailSubject->text());

    MimeText text;
    text.setText(ui->te_emailContent->document()->toPlainText());
    message.addPart(&text);

    MimeAttachment attachment1(new QFile(ui->le_emailAttach1->text()));
    MimeAttachment attachment2(new QFile(ui->le_emailAttach2->text()));
    MimeAttachment attachment3(new QFile(ui->le_emailAttach3->text()));
    MimeAttachment attachment4(new QFile(ui->le_emailAttach4->text()));

    //attachments
    if(ui->le_emailAttach1->text() != NULL){
       message.addPart(&attachment1);
    }

    if(ui->le_emailAttach2->text() != NULL){        
        message.addPart(&attachment2);
    }

    if(ui->le_emailAttach3->text() != NULL){        
        message.addPart(&attachment3);
    }

    if(ui->le_emailAttach4->text() != NULL){        
        message.addPart(&attachment4);
    }


     if (!smtp.connectToHost()) {
         QMessageBox::critical(this,"Faild to connect","cannot connect to host");
         return -1;
     }

     if (!smtp.login()) {
         QMessageBox::critical(this,"Faild to connect","Failed to login");
         return -2;
     }

     smtp.sendMail(message);

     QMessageBox::information(this,"Email Send","operation completed succesfully!");

     smtp.quit();

}

QStringList MainWindow::getRecipientsAddress(QString str){

    QStringList recipients;

    recipients = str.split(QRegExp(";"));

    return recipients;
}


void MainWindow::on_tb_getAttach1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach1->setText(fileName);
}

void MainWindow::on_tb_getAttach2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach2->setText(fileName);
}

void MainWindow::on_tb_getAttach3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach3->setText(fileName);
}

void MainWindow::on_tb_getAttach4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach4->setText(fileName);
}
