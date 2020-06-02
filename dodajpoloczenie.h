#ifndef DODAJPOLOCZENIE_H
#define DODAJPOLOCZENIE_H
#include<QGroupBox>
#include<QObject>
#include<QLineEdit>
#include<QPushButton>

class DodajPoloczenie:public QGroupBox
{
    Q_OBJECT
public:
    DodajPoloczenie(QWidget *parent=0);
public slots:
    void zatwierdzono();
signals:
    void wyslij(QString);
private:
    QLineEdit *lineEdit;
    QPushButton *button;

};

#endif // DODAJPOLOCZENIE_H
