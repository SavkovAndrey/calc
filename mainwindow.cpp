#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first; // переменная для хранения первого числа из 2-х введенных

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

    ui->pushButton_div->setCheckable(true); // возможность устанавливать "галочку"
                                            // что кнопка "выбрана"
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_min->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
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

   // возможность записи 0.001 т.е. чисел начинающихся нулями
   if(ui->result_show->text().contains(".") && button->text() == "0")
   {
       new_label = ui->result_show->text() + button->text();
   } else
        {

   all_numbers = (ui->result_show->text() + button->text()).toDouble();


   // Таким образом мы преобразуем double в string
   // в скобках можно передать просто переменную, но будет 6 знаков и все...
   // а можно дать еще два параметра ( включая 12 - знаков длинны)
   new_label = QString::number(all_numbers, 'g', 12);
        }
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
QPushButton *button =(QPushButton*) sender(); // отслеживаем на какую кнопку нажато

num_first = ui->result_show->text().toDouble(); //сохраняем первое число в переменную

ui->result_show->setText(""); // стираем табло , что бы вводить второе число
                              // после нажатия кнопки операции

button->setChecked(true);  // помечаем какая кнопка нажата,
                           // что бы в методе равенства этим воспользоваться
}


void MainWindow::on_pushButton_ac_clicked()
{
   ui->pushButton_plus->setChecked(false);
   ui->pushButton_min->setChecked(false);
   ui->pushButton_mul->setChecked(false);
   ui->pushButton_div->setChecked(false); // при нажатии на = не сработают проверки

   ui->result_show->setText("0");         //  на экране ставим 0

}


void MainWindow::on_pushButton_equal_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();



    if(ui->pushButton_plus->isChecked())
    {
        labelNumber = num_first + num_second;             // проводим саму операцию
        new_label = QString::number( labelNumber, 'g', 12); // переводим в стринг
        ui->result_show->setText(new_label);                // выводим на Лэйбл
        ui->pushButton_plus->setChecked(false);             // ставим галочку в фолс

    }else if(ui->pushButton_min->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number( labelNumber, 'g', 12);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    }else if(ui->pushButton_div->isChecked())
    {
            if(num_second == 0)
            {
                ui->result_show->setText("0");
            }else
            {
                labelNumber = num_first / num_second;
                new_label = QString::number( labelNumber, 'g', 12);
                 ui->result_show->setText(new_label);
            }

        ui->pushButton_plus->setChecked(false);

    }else if(ui->pushButton_mul->isChecked())
    {

        labelNumber = num_first * num_second;
        new_label = QString::number( labelNumber, 'g', 12);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
}

