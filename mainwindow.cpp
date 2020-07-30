#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIdentityProxyModel>

MainWindow::MainWindow(QWidget *parent)
	   : QMainWindow(parent)
	   , ui(new Ui::MainWindow)
	{
		ui->setupUi(this);	


		QStandardItemModel *model = new QStandardItemModel;
		QStandardItem *item;


		// формируем таблицу
		QStringList horizontalHeader,verticalHeader;
		//заполняем
		//Заголовки столбцов (5)
		horizontalHeader.append("Арбайг");
		horizontalHeader.append("Страдиг");
		horizontalHeader.append("Фаша");
		horizontalHeader.append("Армиг");
		horizontalHeader.append("Сентиг");
		//Заголовки строк (12)
		verticalHeader.append("1-ая неделя Эмбрий");
		verticalHeader.append("2-ая неделя Эмбрий");
		verticalHeader.append("1-ая неделя Неззий");
		verticalHeader.append("2-ая неделя Неззий");
		verticalHeader.append("1-ая неделя Витий");
		verticalHeader.append("2-ая неделя Витий");
		verticalHeader.append("1-ая неделя Велдий");
		verticalHeader.append("2-ая неделя Велдий");
		verticalHeader.append("1-ая неделя Сенсий");
		verticalHeader.append("2-ая неделя Сенсий");
		verticalHeader.append("1-ая неделя Шизия");
		verticalHeader.append("2-ая неделя Шизия");
		   

		//число элементов таблицы
		auto const horizontalHeader_int = 5; int verticalHeader_int = 12;
		auto horizontalHeader_int_X = 0, verticalHeader_int_X = 0 ; //для вывода на экран, не инцилизировать!
		int total_number_of_cells = horizontalHeader_int * verticalHeader_int;
        int buffer[4] = {0,0,0,0}; //для вывода информации в таблицу
        buffer[3] = horizontalHeader_int; buffer[4] = verticalHeader_int; // limit

        //
		model->setHorizontalHeaderLabels(horizontalHeader);
		model->setVerticalHeaderLabels(verticalHeader);

        //check time program + datatime
		m_startTime = QTime::currentTime();
        QString info = updateTime(0);
		startTimer(1000);

        for (auto eDx = 0 ; eDx > total_number_of_cells, ++eDx;) { //
            for(int i = 0; i == 3; ++i){
                  int iI = i + 2;
                   if(buffer[i] == buffer[iI]) //проверяем
                    {
                       buffer[i]=0;//сбрасываем до 0
                    }
                       else
                    {

                    }
            }

            item = new QStandardItem(QString(eDx + " - " + info));
            model->setItem(buffer[1], buffer[2], item);
		}

		//tableView
        ui->tableView->setModel(model); ui->tableView->resizeRowsToContents(); ui->tableView->resizeColumnsToContents();
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);




	}
	QDate Start_of_the_Republic_of_Embronia(2019, 5, 4); //2019 год май(5 месяц) 4 число
	QDate The_current_date =  QDate::currentDate(); //текущая дата


QString MainWindow::updateTime(int _ms)
	{
	   QTime time = QTime(0,0,0).addMSecs(_ms);
	   QDateTime std_time = QDateTime::currentDateTime(); QTimeZone timezone("Europe/Moscow"); std_time = std_time.toTimeZone(timezone);
	   //текущее время + дата, TIMEZONE = Europe/Moscow or UTC+4
	   qint64 days = -1 * (The_current_date.daysTo(Start_of_the_Republic_of_Embronia)); //получаем разницу дней от создания и текущей
	   ui->label_time_std->setText("Календарь   (Текущее время :  " + std_time.toString("dd.MM.yyyy - hh:mm:ss" ) + " (MSK) ) Время работы календаря : "  + time.toString("hh:mm:ss") );

	   qint64 years,month;

	   //расчет
	   years = (days/60);
	   month = (days/10) - years*6 ;
	   days = days - years*60 - month*10 ;

	   //вывод пройденого времени
	   ui->label_time->setText(QString::number(years) + " Лет " +  QString::number(month) + " Месяцев " +  QString::number(days) + " Дней " + std_time.toString("hh:mm:ss" ));

       QString return_logs = QString::number(years);
       return return_logs;
	}

void MainWindow::timerEvent(QTimerEvent *)
	{
	  int diffMs = m_startTime.msecsTo(QTime::currentTime());
	  updateTime(diffMs);
	}

MainWindow::~MainWindow()
	{
	  delete ui;
	}



	/*
	########################################################################################
	// Window movement Func [СalendarER] - [Developer Sergey Leshkevich]
	########################################################################################
	*/
void MainWindow::mousePressEvent(QMouseEvent *event)
	{
	MainWindow::m_nMouseClick_X_Coordinate = event->x();MainWindow::m_nMouseClick_Y_Coordinate = event->y();
	}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
	move(event->globalX()-MainWindow::m_nMouseClick_X_Coordinate,event->globalY()-MainWindow::m_nMouseClick_Y_Coordinate);
	}
	/* ######################################################################################## */


void MainWindow::on_pushButton_close_clicked()
	{
	close();
	}


