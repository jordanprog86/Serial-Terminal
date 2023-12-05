#include "console.h"
#include "ui_console.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_USE_NAMESPACE

Console::Console(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Console)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->gridLayout);
    m_serialPort = new QSerialPort;


QString html;
html += "<body><center>";
html += "<br><img src ='qrc:/images/Copie de TERMINAL.png'>";
html += "<h1> TERMINAL 1.0.21</h1><br> Copyright © Jordan Tchoulayeu<br>Released the 29.04.2018<br>Updated the 27.03.2021</center><br></body>";

ui->msgLog->append(html);

        foreach (const QSerialPortInfo &m_port, QSerialPortInfo::availablePorts()) {
        ui->msgLog->append( m_port.portName());
        ui->msgLog->append(m_port.manufacturer());
        ui->msgLog->append(m_port.description());
        ui->msgLog->append("-------------");
        ui->comportsBox->addItem(m_port.portName());
    }


       connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(readyRead()));





}

Console::~Console()
{
    delete ui;
}

void Console::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void Console::readyRead()
{


QByteArray line = m_serialPort->readAll();

ui->msgLog->append(line);

qDebug()<<line;


}

void Console::on_okButton_clicked()
{
      QString msg = ui->commandWriter->text() +"\r\n";
      m_serialPort->write(msg.toLatin1());
      s = msg;
      ui->commandWriter->clear();
}

void Console::on_startButton_clicked()
{
    m_serialPort->close();
    m_serialPort->setPort(QSerialPortInfo(ui->comportsBox->currentText()));
    if(m_serialPort->open(QIODevice::ReadWrite))
    {
        qDebug()<<"modem GSM OK";
       ui->msgLog->append(QString("<font color =lightblue> connected to %1 </font>").arg(ui->comportsBox->currentText()));
    }
    else
    {
        qDebug()<<m_serialPort->errorString();
    }
}

void Console::on_findButton_clicked()
{
   ui->comportsBox->clear();
    foreach (const QSerialPortInfo &m_port, QSerialPortInfo::availablePorts()) {
        ui->msgLog->append( m_port.portName());
        ui->msgLog->append(m_port.manufacturer());
        ui->msgLog->append(m_port.description());
        ui->msgLog->append("-------------");

        ui->comportsBox->addItem(m_port.portName());
    }
}
