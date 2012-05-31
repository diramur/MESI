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

struct Node { // ��������� �������� ������
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
{ // ������� ������ �������� � ����� ������
	Node* temp = tail;
	if( first == NULL ) 
	{ // ������ ������
		Node* list = new(Node);
		first = list;
		tail = list;
		first=tail;
	}else{ // �������� ������
		tail->next = new(Node);
		tail->next->prev=tail; //��� ���������� � ����� ����� ��������� ������� ��� ���������� ����� tail'�
		tail = tail->next;
	}
	tail->prev=temp;
	tail->next=first; // ���������, ��� ��� ����� ��������� ������� ������
	first->prev=tail;
	tail->name=name;
}

void List::AddFront(string name)
{ // ������ ������ �������� � ������ ������
	if( first == NULL ) 
	{ // ������ ������
		Node* list = new(Node);
		first = list;
		tail = list;
		first=tail;
	}
	else
	{ // �������� ������
		first->prev=new Node;
		first->prev->next=first;
		first=first->prev;
	}

	first->prev=tail; // ���������, ��� ��� ����� ������ ������� ������
	tail->next=first;

	first->name=name;	
}


void List::DelAll()
{ // �������� ������, ���������� ��� ������
system("cls");
	if (!first) { // first=NULL
		setlocale(LC_ALL,"Russian");
		cout << "� ������ 0 ���������. �������� ����������\n";
		cout << "������� ����� �������";
        getch();
	}
	else {
		Node* tmp;
		Node* list = first;
		while(list!=tail){
			tmp = list;
			list = list->next;
			free(tmp); // �������� �������� �� ����� ������
		}
		free(list);
		list=NULL;
		first=tail;
		first=NULL;
		tail=NULL;
		cout << "� ������ 0 ���������";
		getch();
		system("cls");
	}
}

bool List::DelBegin() {
     	if(!first){
      system("cls");
		setlocale(LC_ALL,"Russian");
		cout << "� ������ 0 ���������. �������� ����������\n";
		cout << "������� ����� �������";
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
		cout << "� ������ 0 ���������";
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
		cout << "� ������ 0 ���������. �������� ����������\n";
		cout << "������� ����� �������";
        getch();
		return false;
	}
	Node* temp= new Node;
	tail->prev->next=first;
	tail->next->prev=tail->prev;
	first->prev=tail->prev;
	if (first==tail){
		cout << "� ������ 0 ���������";
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
		cout << "| � ��������  |                         ��� ��������                           |" << endl;
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
		cout << "� ������ 0 ���������. �������� ����������\n";
		cout << "������� ����� �������";
		getch();
}

void List::Print_list() {
     system("cls");
	if (first!=NULL) {
		int key;

		Node* list=first;
		do {
			setlocale(LC_ALL,"Russian");
			cout << "������� ������ ��� ��������:\n\n";
			cout << " >> " << list->name << "\n"; // ����� ����� �������� �������� ������
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
		while( key!=32); // ���� �� ����� ������
	}
	else {
		cout << "� ������ 0 ���������. �������� ����������\n";
		cout << "������� ����� �������";
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

		FILE*f; // ��������� �� ����
		f=fopen("list.txt","w"); // �� ���� ��������� ���������� � ����� list_file.txt, ������� ��� ��������� � ������� ����������
		fclose(f); // ���������
		f=fopen("list.txt","a"); // ��������� ��� ������
		fwrite(&count,sizeof(int),1,f); // ���������� ����� fwrite
		while(list!=tail) {
			fwrite(&list->name,sizeof(Node),1,f);
			list=list->next;
		}
		fwrite(&tail->name,sizeof(Node),1,f);
		fclose(f);
		list=first;
	}
	else {
		cout << "� ������ 0 ���������. ���������� � ���� ����������\n";
		cout << "������� ����� �������";
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
		tail->next=first; // ���������, ��� ��� ����� ��������� ������� ������
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
		cout<<"���� �� ����������. �������� ����������\n";
		cout<<"������� ����� �������";
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
			cout << "������� ���� ��������: ";
			error = 0;
			cin >> pos;
			if(cin.fail()) { // ���� ������ ��� �����
				cout << "���� ������� �������, ������ ���� �����\n";
				error = 1;
			}
			cin.clear(); fflush(stdin); // ������� ������ �����
		}while(error==1);
		cout << "������� �������� ��������: ";
		cin.sync();
		getline(cin, tmp.name);
		cin.clear(); fflush(stdin); 
		Node*list=first;
		for (int i=0;i<pos;i++)
		list=list->next;
		list->name=tmp.name;
	}else{
		cout << "������ ����. �������������� ����������\n";
		cout << "������� ����� �������";
		getch();
	}
}


void print_menu(int point, int size, string name, string *base){ //<������� �����>,<������ ����>,<��� ����>,<���� ������ ����(�� ������)>//
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
     cout << "�������" << endl;
     getch();
}

int func_switch (int temp_1, int temp_2, int max){//<��� �����>,<������� ���������>,<������ ����>
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
        if (temp_2 < 0){      //����������� ����
           temp_2 = max-1;            
        }
        if (temp_2 >= max){
           temp_2 = 0;   
        }
     return temp_2; //����������� ����� ������� ���������
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
    int sel_item = 1; //������� ���������
    int sel_sub_item = 1;//������� ���������
    int a;
    int key = 0;
    bool exit = false; //���� ������
    bool sub_exit = false; //���� ������
    menu general;
    general.name = "������� ����";
    general.size = 7;
    general.base[1] = "1) ������ � ������� ";
    general.base[2] = "2) �������� ";
    general.base[3] = "3) ������� ";
    general.base[4] = "4) ������������� ";
    general.base[5] = "5) �������� ";
    general.base[6] = "6) ���������� ";
    general.base[0] = "0) ����� ";
    
    menu level_1;// ������ � �������
    level_1.size = 3;
    level_1.base[1] = "1) ���������� ������ � ���� ";
    level_1.base[2] = "2) �������� ������ �� ����� ";
    level_1.base[0] = "0) ����� ";
    
    menu level_2;// ����������
    level_2.size = 3;
    level_2.base[1] = "1) � ������ ";
    level_2.base[2] = "2) � ����� ";
    level_2.base[0] = "0) ����� ";
    
    menu level_3;// ��������
    level_3.size = 4;
    level_3.base[1] = "1) ������ ";
    level_3.base[2] = "2) ����� ";
    level_3.base[3] = "3) ������ ";
    level_3.base[0] = "0) ����� ";
    
    menu level_4;// ��������������
    level_4.size = 2;
    level_4.base[1] = "1) �� ����� ";
    level_4.base[0] = "0) ����� ";
    
    menu level_5;// �����
    level_5.size = 3;
    level_5.base[1] = "1) �������� ";
    level_5.base[2] = "2) ���������� ";
    level_5.base[0] = "0) ����� ";
    
    menu level_6;// ����������
    level_6.size = 2;
    level_6.base[1] = "1) ���������� �-� �� ����� ";
    level_6.base[0] = "0) ����� ";
    
    menu m_exit; // �����
    m_exit.size = 2;
    m_exit.base[0] = "1) ��";
    m_exit.base[1] = "0) ���������";
    
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
                              switch (sel_sub_item){       //����� � �������
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
					                          	                cout << "������� �������� ��������: ";
                  	                                            cin.sync();
						                                        getline(cin, tmp.name);
						                                        cin.clear(); fflush(stdin); // ������� ������ �����
					                                           	X.AddFront(tmp.name); // ���������� �������� � ������ ������
					                                            system("cls"); // ������� ������
                                                              break;
                                         case 2:                system("cls");
                                                                cout << "������� �������� ��������: ";
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
               case 0: m_exit.name = "0) ����� ";
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
           m_exit.name = "0) ����� ";
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
    List list; // list �������� ���������� ������ List
	list.Menu(); //����� ������� ����
	return 0;
}
