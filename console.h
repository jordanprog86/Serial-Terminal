#ifndef CONSOLE_H
#define CONSOLE_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
namespace Ui {
class Console;
}

class Console : public QMainWindow
{
    Q_OBJECT

public:
    explicit Console(QWidget *parent = 0);
    ~Console();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Console *ui;
    QSerialPort *m_serialPort;
    QSerialPortInfo *m_portCount;
    QString s;
private slots:
    void readyRead();
    void on_okButton_clicked();
    void on_startButton_clicked();
    void on_findButton_clicked();
};

#endif // CONSOLE_H
