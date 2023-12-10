#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// конектим (при работе с кнопкой 0->отслеживаем сигнал "нажатие"->
    // мы работаем с "этим" объектом-> какой СЛОТ должен выполниться
    // СЛОТЫ - добавили в заголовочном файле
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_pm,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_prc,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    //sender() - взвращает на "нажатие" кнопки
    // преобразуем sender  к типу QPushButton
    // и создаем указатель такого же типа, что бы хранить значение
QPushButton *button =(QPushButton*) sender();
   double all_numbers; // переменная для хранения числа на дисплее
   QString new_label;  // текстовая переменная, что бы использовать в setText()
   all_numbers = (ui->result_show->text() + button->text()).toDouble();


   // Таким образом мы преобразуем double в string
   // в скобках можно передать просто переменную, но будет 6 знаков и все...
   // а можно дать еще два параметра ( включая 12 - знаков длинны)
   new_label = QString::number(all_numbers, 'g', 12);

   // берем наш label->показать текст-> наш указатель->
    // он через connect получает signal нужной кнопки->
    // выводим текст этой кнопки
//ui->result_show->setText(button->text()); // заменяем на переменную,
   // что бы выводить не одну цифру (нажатую), а троку из цифр
ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    // Если информация на дисплее НЕ содержит точку, тогда добовляем точку
    if(!(ui->result_show->text().contains('.')))
    // берем данные с label главного и присваеваим им
    // значенние тех же данных + точка
    ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::operations()
{

QPushButton *button =(QPushButton*) sender();
   double all_numbers;
   QString new_label;

   // Если нажата кнопка +/- то:
   if(button->text() == "+/-")
   {

       // текст с дисплея переводим в double
       // умножаем на -1, что бы сменить знак
   all_numbers = (ui->result_show->text()).toDouble();
   all_numbers = all_numbers * -1;

   new_label = QString::number(all_numbers, 'g', 12);
   ui->result_show->setText(new_label);
   }
   else if(button->text() == "%")
   {

       // текст с дисплея переводим в double
       // умножаем на 0.01, что бы получить %
   all_numbers = (ui->result_show->text()).toDouble();
   all_numbers = all_numbers * 0.01;

   new_label = QString::number(all_numbers, 'g', 12);
   ui->result_show->setText(new_label);
   }
}


void MainWindow::math_operations()
{

}


void MainWindow::on_pushButton_ac_clicked()
{

}


void MainWindow::on_pushButton_equal_clicked()
{

}

