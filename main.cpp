#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "windows.h"
#include <time.h>
#include <cstdlib>
using namespace std;

struct Node { // структура элемента списка
	string name;
	Node* next;
	Node* prev;
};

class List {
private: Node*first;
		 Node*tail;
public: void Print();
		void Print_list();
		void AddFront(string name);
		void AddBack(string name);
		void Init();
		bool DelBack();
		bool DelBegin();
		void DelAll();
		void Upload();
		void Unload();
		void SortbyKey();
		void Menu();
		void EditbyKey();
};

void List::Init() {
	first=NULL;
	tail=NULL;
}

void List::AddBack(string name)
{ // вставка нового элемента в конец списка
	Node* temp = tail;
	if( first == NULL ) 
	{ // пустой список
		Node* list = new(Node);
		first = list;
		tail = list;
		first=tail;
	}else{ // непустой список
		tail->next = new(Node);
		tail->next->prev=tail; //при добавлении в конец новый последний элемент ему предыдущий равен tail'у
		tail = tail->next;
	}
	tail->prev=temp;
	tail->next=first; // указываем, что это будет последний элемент списка
	first->prev=tail;
	tail->name=name;
}

void List::AddFront(string name)
{ // втавка нового элемента в начало списка
	if( first == NULL ) 
	{ // пустой список
		Node* list = new(Node);
		first = list;
		tail = list;
		first=tail;
	}
	else
	{ // непустой список
		first->prev=new Node;
		first->prev->next=first;
		first=first->prev;
	}

	first->prev=tail; // указываем, что это будет первый элемент списка
	tail->next=first;

	first->name=name;	
}


void List::DelAll()
{ // очистить память, выделенную под список
system("cls");
	if (!first) { // first=NULL
		setlocale(LC_ALL,"Russian");
		cout << "В списке 0 элементов. Удаление невозможно\n";
		cout << "Нажмите любую клавишу";
        getch();
	}
	else {
		Node* tmp;
		Node* list = first;
		while(list!=tail){
			tmp = list;
			list = list->next;
			free(tmp); // удаление элемента из самой памяти
		}
		free(list);
		list=NULL;
		first=tail;
		first=NULL;
		tail=NULL;
		cout << "В списке 0 элементов";
		getch();
		system("cls");
	}
}

bool List::DelBegin() {
     	if(!first){
      system("cls");
		setlocale(LC_ALL,"Russian");
		cout << "В списке 0 элементов. Удаление невозможно\n";
		cout << "Нажмите любую клавишу";
        getch();
		return false;
	}
	Node* list=first;
	Node* temp= new Node;
	if (list->next!=first) {
		list->prev->next=list->next;
		list->next->prev=list->prev;
		temp=list;
		list=list->next;
		first=list;
		free(temp);
		first->prev=tail;
		system("cls");
		return true;
	}else{
		cout << "В списке 0 элементов";
		getch();
		system("cls");
		free(list);
		first=NULL;
		tail=NULL;
		list=NULL;
		return true;
	}
}

bool List::DelBack() 
{	if (!first) {
    system("cls");
		setlocale(LC_ALL,"Russian");
		cout << "В списке 0 элементов. Удаление невозможно\n";
		cout << "Нажмите любую клавишу";
        getch();
		return false;
	}
	Node* temp= new Node;
	tail->prev->next=first;
	tail->next->prev=tail->prev;
	first->prev=tail->prev;
	if (first==tail){
		cout << "В списке 0 элементов";
		getch();
		system("cls");
		free(first);
		first=NULL;
		tail=NULL;
		return true;
	}
	temp=tail;
	tail=tail->prev;
	free(temp);
	return true;
}


void List::Print() {
     system("cls");
	setlocale(LC_ALL,"Russian");
	if (first!=NULL) {
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "| № элемента  |                         Имя элемента                           |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	
		Node* list=first;
		Node* q=first->prev;

		int i=0;
		while (list->next!=first) { 
			i++;
			cout << "|     " << i;
			if (i<10)
				cout << " ";
			cout << "      |                           ";

			string temp=list->name;
			string space=" ";
			int count=0;
			while (temp.size()<35) {
						temp=temp+space;
						count++;
			}
			cout << "  " << list->name; 
			for (int i=0;i<count;i++)
				cout << " ";
			cout << "|" << endl;
			list=list->next;
		}
			i++;
			cout << "|     " << i;
			if (i<10)
				cout << " ";
			cout << "      |                           ";
			string temp=q->name;
			string space=" ";
			int count=0;
			while (temp.size()<35) {
						temp=temp+space;
						count++;
			}
			cout << "  " << q->name; 
			for (int i=0;i<count;i++)
				cout << " ";
			cout << "|" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		list=first;
	}
	else 
		cout << "В списке 0 элементов. Просмотр недоступен\n";
		cout << "Нажмите любую клавишу";
		getch();
}

void List::Print_list() {
     system("cls");
	if (first!=NULL) {
		int key;

		Node* list=first;
		do {
			setlocale(LC_ALL,"Russian");
			cout << "Нажмите пробел для возврата:\n\n";
			cout << " >> " << list->name << "\n"; // вывод полей текущего элемента списка
			key=getch();
			if (key==227) 
				getch();
			system("cls"); 
			switch(key) {
				case 77:
					list = list->next;
					break;
				case 75:
					list = list->prev;
					break;
			}
		}
		while( key!=32); // пока не нажат пробел
	}
	else {
		cout << "В списке 0 элементов. Просмотр недоступен\n";
		cout << "Нажмите любую клавишу";
        getch();
	}
}


void List::Upload(void) {
          system("cls");
	if (first!=NULL) {
		int count=1;
		Node* list=first;

		while(list!=tail) {
			count++;
			list=list->next;
		}
		list=first;

		FILE*f; // указатель на файл
		f=fopen("list.txt","w"); // мы этот указатель привзываем к файлу list_file.txt, сначала его открываем и удаляем содержимое
		fclose(f); // закрываем
		f=fopen("list.txt","a"); // открываем для записи
		fwrite(&count,sizeof(int),1,f); // записываем через fwrite
		while(list!=tail) {
			fwrite(&list->name,sizeof(Node),1,f);
			list=list->next;
		}
		fwrite(&tail->name,sizeof(Node),1,f);
		fclose(f);
		list=first;
	}
	else {
		cout << "В списке 0 элементов. Сохранение в файл невозможно\n";
		cout << "Нажмите любую клавишу";
        getch();
	}
}

void List::Unload() {
     system("cls");
	FILE *fp;
	fp=fopen("list.txt","r");
	if (fp!=NULL){
		int count;
		if (first!=NULL) {
			Node* tmp;
			Node* list = first;
			while(list!=tail) {
				tmp = list;
				list = list->next;
				free(tmp);
			}
			free(list);
			list=NULL;
			first=tail;
			first=NULL;
			tail=NULL;
		}
		Node* list = new(Node);
		first = list;
		tail = list;
		tail->next=first; // указываем, что это будет последний элемент списка
		first->prev=tail;
		FILE*f;
		f=fopen("list.txt","r");
		fread(&count,sizeof(int),1,f);;
		fread(&list->name,sizeof(Node),1,f);
		for (int i=0;i<count-1;i++) {
			Node* temp = tail;
			tail->next = new(Node);
			tail->next->prev=tail;
			tail = tail->next;
			fread(&tail->name,sizeof(Node),1,f);
			tail->prev=temp;
			tail->next=first; 
			first->prev=tail;
		}
		list=first;
	}else{
		cout<<"Файл не существует. Выгрузка невозможна\n";
		cout<<"Нажмите любую клавишу";
        getch();
	}
}

void List::EditbyKey(){
system("cls");
	if (first!=NULL){
		int error;
		Node tmp;
		int pos;
		do{
			cout << "Введите ключ элемента: ";
			error = 0;
			cin >> pos;
			if(cin.fail()) { // если ошибка при вводе
				cout << "Ключ указано неверно, должно быть число\n";
				error = 1;
			}
			cin.clear(); fflush(stdin); // очистка буфера ввода
		}while(error==1);
		cout << "Введите название элемента: ";
		cin.sync();
		getline(cin, tmp.name);
		cin.clear(); fflush(stdin); 
		Node*list=first;
		for (int i=0;i<pos;i++)
		list=list->next;
		list->name=tmp.name;
	}else{
		cout << "Список пуст. Редактирование невозможно\n";
		cout << "Нажмите любую клавишу";
		getch();
	}
}


void print_menu(int point, int size, string name, string *base){ //<позиция ключа>,<размер меню>,<имя меню>,<сами пункты меню(по ссылке)>//
        system("cls");
        cout << name << endl;
        for (int i = 1; i < size; i++){
            if (point == i) {
               cout << " * ";
            }else{
                 cout << "   ";
            }
            cout << base[i];
            cout << endl;
        }
        if (point == 0){
           cout << " * ";             
        }else{
             cout << "   ";
        }
        cout << base[0];
}

void im_func(){
     system("cls");
     cout << "Функция" << endl;
     getch();
}

int func_switch (int temp_1, int temp_2, int max){//<код ключа>,<позиция указателя>,<пункты меню>
     switch (temp_1){
        case 72: temp_2 = temp_2 - 1; 
                 break;
        case 80: temp_2 = temp_2 + 1; 
                 break;
        case 48: if (0 <= max){
                    temp_2 = 0;
                 }
                 break;
        case 49: if (1 < max) {
                    temp_2 = 1;
                 }
                 break;
        case 50: if (2 < max) {
                    temp_2 = 2;
                 }
                 break;
        case 51: if (3 < max) {
                    temp_2 = 3;
                 }
                 break;
        case 52: if (4 < max) {
                    temp_2 = 4;
                 }
                 break;
        case 53: if (5 < max) {
                    temp_2 = 5;
                 }
                 break;       
        case 54: if (6 < max) {
                    temp_2 = 6;
                 }
                 break;
        case 55: if (7 < max) {
                    temp_2 = 7;
                 }
                 break;
        case 56: if (8 < max) {
                    temp_2 = 8;
                 }
                 break;
        case 57: if (9 < max) {
                    temp_2 = 9;
                 }
                 break;
        }
        if (temp_2 < 0){      //закругление меню
           temp_2 = max-1;            
        }
        if (temp_2 >= max){
           temp_2 = 0;   
        }
     return temp_2; //возвращение новой позиции указателя
}


void List::Menu(){
     struct menu{
            int size;
            string name;
            string base[10];
       };
    List X;
	X.Init();
	int error;
	Node tmp;
       setlocale(LC_ALL,"Russian");
    int sel_item = 1; //позиция указателя
    int sel_sub_item = 1;//позиция указателя
    int a;
    int key = 0;
    bool exit = false; //флаг выхода
    bool sub_exit = false; //флаг выхода
    menu general;
    general.name = "Главное меню";
    general.size = 7;
    general.base[1] = "1) Работа с файлами ";
    general.base[2] = "2) Добавить ";
    general.base[3] = "3) Удалить ";
    general.base[4] = "4) Редактировать ";
    general.base[5] = "5) Показать ";
    general.base[6] = "6) Сортировка ";
    general.base[0] = "0) Выход ";
    
    menu level_1;// Работа с файлами
    level_1.size = 3;
    level_1.base[1] = "1) Сохранение списка в файл ";
    level_1.base[2] = "2) Выгрузка списка из файла ";
    level_1.base[0] = "0) Назад ";
    
    menu level_2;// Добавление
    level_2.size = 3;
    level_2.base[1] = "1) В начало ";
    level_2.base[2] = "2) В конец ";
    level_2.base[0] = "0) Назад ";
    
    menu level_3;// Удаление
    level_3.size = 4;
    level_3.base[1] = "1) Начало ";
    level_3.base[2] = "2) Конец ";
    level_3.base[3] = "3) Полное ";
    level_3.base[0] = "0) Назад ";
    
    menu level_4;// редактирование
    level_4.size = 2;
    level_4.base[1] = "1) По ключу ";
    level_4.base[0] = "0) Назад ";
    
    menu level_5;// Показ
    level_5.size = 3;
    level_5.base[1] = "1) Таблицей ";
    level_5.base[2] = "2) Прокруткой ";
    level_5.base[0] = "0) Назад ";
    
    menu level_6;// сортировка
    level_6.size = 2;
    level_6.base[1] = "1) Сортировка я-а по ключу ";
    level_6.base[0] = "0) Назад ";
    
    menu m_exit; // Выход
    m_exit.size = 2;
    m_exit.base[0] = "1) Да";
    m_exit.base[1] = "0) Вернуться";
    
    do {
        print_menu(sel_item, general.size, general.name, general.base);
        key = getch();
        sel_sub_item = 1;             
        if (key == 13){
           switch (sel_item){
               case 1: level_1.name = general.base[1];
                       do{
                           key = 0;
                           sub_exit = false;
                           print_menu(sel_sub_item, level_1.size, level_1.name, level_1.base);
                           key = getch();
                           if (key == 13) {
                              switch (sel_sub_item){       //выбор в подменю
                                     case 1: X.Upload();break;
                                     case 2: X.Unload();break;
                                     case 0: sub_exit = true;break;
                              }
                           }else{
                                 sel_sub_item = func_switch(key, sel_sub_item, level_1.size);
                           }
                           if (key == 27){
                              sub_exit = true;
                              key = 0;
                           }           
                       }while(sub_exit != true);
                       break;
               case 2: level_2.name = general.base[2];
                       do{
                           key = 0;
                           sub_exit = false;
                           print_menu(sel_sub_item, level_2.size, level_2.name, level_2.base);
                           key = getch();
                               if (key == 13) {
                                  switch (sel_sub_item){
                                         case 1:                system("cls");
					                          	                cout << "Введите название элемента: ";
                  	                                            cin.sync();
						                                        getline(cin, tmp.name);
						                                        cin.clear(); fflush(stdin); // очистка буфера ввода
					                                           	X.AddFront(tmp.name); // добавление элемента в начало списка
					                                            system("cls"); // очистка экрана
                                                              break;
                                         case 2:                system("cls");
                                                                cout << "Введите название элемента: ";
                                                                cin.sync();
						                                        getline(cin, tmp.name);
						                                        cin.clear(); fflush(stdin);
						                                        X.AddBack(tmp.name);
						                                        system("cls");
                                                              break;
                                         case 0: sub_exit = true;break;
                                  }            
                               }else{
                                     sel_sub_item = func_switch(key, sel_sub_item, level_2.size);
                               }
                           if (key == 27){
                                  sub_exit = true;
                                  key = 0;
                           }
                       }while(sub_exit != true);
                       break;
               case 3: level_3.name = general.base[3];//delete
                       do{
                           key = 0;
                           sub_exit = false;
                           print_menu(sel_sub_item, level_3.size, level_3.name, level_3.base);
                           key = getch();
                           if (key == 13) {
                              switch (sel_sub_item){
                                     case 1: X.DelBegin();break;
                                     case 2: X.DelBack();break;
                                     case 3: X.DelAll();break;
                                     case 0: sub_exit = true;
                              }            
                           }else{
                                 sel_sub_item = func_switch(key, sel_sub_item, level_3.size);
                           }
                           if (key == 27){
                              sub_exit = true;
                              key = 0;
                           }
                       }while(sub_exit != true);
                       break;
               case 4: level_4.name = general.base[4];//edit
                       do{
                           key = 0;
                           sub_exit = false;
                           print_menu(sel_sub_item, level_4.size, level_4.name, level_4.base);
                           key = getch();
                           if (key == 13) {
                              switch (sel_sub_item){
                                     case 1: X.EditbyKey();break;
                                     case 0: sub_exit = true;
                              }            
                           }else{
                                 sel_sub_item = func_switch(key, sel_sub_item, level_4.size);
                           }
                           if (key == 27){
                                  sub_exit = true;
                                  key = 0;
                           }
                       }while(sub_exit != true);
                       break;
               case 5: level_5.name = general.base[5];//show
                       do{
                           key = 0;
                           sub_exit = false;
                           print_menu(sel_sub_item, level_5.size, level_5.name, level_5.base);
                           key = getch();
                           if (key == 13 && key != 27) {
                              switch (sel_sub_item){
                                     case 1: X.Print();break;
                                     case 2: X.Print_list();break;
                                     case 0: sub_exit = true;
                              }            
                           }else{
                                 sel_sub_item = func_switch(key, sel_sub_item, level_5.size);
                           }
                           if (key == 27){
                                  sub_exit = true;
                                  key = 0;
                           }
                       }while(sub_exit != true);
                       break;
               case 6: level_6.name = general.base[6];//sort
                       do{
                           key = 0;
                           sub_exit = false;
                           print_menu(sel_sub_item, level_6.size, level_6.name, level_6.base);
                           key = getch();
                           if (key == 13){
                              switch (sel_sub_item){
                                     case 1: im_func();break;
                                     case 0: sub_exit = true;
                              }            
                           }else{
                                 sel_sub_item = func_switch(key, sel_sub_item, level_6.size);
                           }
                           if (key == 27){
                                  sub_exit = true;
                                  key = 0;
                           }
                       }while(sub_exit != true);
                       break;                       
               case 0: m_exit.name = "0) Выход ";
                       do{
                          key = 0;
                          sub_exit = false;
                          print_menu(sel_sub_item, m_exit.size, m_exit.name, m_exit.base);
                          key = getch();
                          if (key == 13) {
                             switch (sel_sub_item){
                                    case 0: system("cls");
                                            exit = true;
                                            sub_exit = true;
                                            break;
                                    case 1: sub_exit = true;
                                            break;
                             }
                          }else{
                                sel_sub_item = func_switch(key, sel_sub_item, m_exit.size);
                          }
                          if (key == 27){
                             sub_exit = true;
                             key = 0;
                          }
                       }while(sub_exit != true);
                       break;
        }
        }else{
              sel_item = func_switch(key, sel_item, general.size);
        }
        if (key == 27){
           m_exit.name = "0) Выход ";
           do{
              sel_item = 0;
              key = 0;
              sub_exit = false;
              print_menu(sel_sub_item, m_exit.size, m_exit.name, m_exit.base);
              key = getch();
              sel_sub_item = func_switch(key, sel_sub_item, m_exit.size);
              if (key == 13){
                 switch (sel_sub_item){
                        case 0: system("cls");
                                exit = true;
                                sub_exit = true;
                                break;
                        case 1: sub_exit = true;
                                break;
                 }
              }
              if (key == 27){
                 sub_exit = true;
              }
           }while(sub_exit != true);
        }  
    }while (exit != true);
     }
       
int main()
{
    List list; // list является переменной класса List
	list.Menu(); //вызов функции меню
	return 0;
}
