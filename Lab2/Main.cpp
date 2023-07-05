#include <graphics.h>
#include <string>
#include<iostream>
#include"Dot.h"
#include"setCircle.h"
#include"setColor.h"
#include"Shape.h"
#include"setLine.h"
#include"setRectangle.h"
#include"setTriangle.h"
#include"ChangeToFunction.h"
using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;

int setCircle::ExistingCircleNumber = 0;
int setRectangle::ExistingRectangleNumber = 0;
int setTriangle::ExistingTriangleNumber = 0;
int main() {
    //��ʼ������
    initgraph(800, 800);


    //�����߶ο���
    char c3[1001];
    ::inputbox_getline("Please enter the linewidth:", "", c3, 1000);
    int linewidth = ChangeToInteger(c3);
    setlinewidth(linewidth);


   

    //�����жϴ���ͼ�����͵��ַ���
    char str[1001];
    string s{};

    while (1) {

        //���봴��ͼ�ε�����
        inputbox_getline("The kind you wanna create?(circle/rectangle/triangle)", "", str, 1000);
        s = str;

        //�������ָ��
        Shape* baseptr = nullptr;

        //Բ��
        if (s == "circle") {
            //�����������
            char s1[1001];
            inputbox_getline("Please enter the x coordinate of the circle:", "", s1, 1000);
            int x = ChangeToInteger(s1);

            char s2[1001];
            inputbox_getline("Please enter the y coordinate of the circle:", "", s2, 1000);
            int y = ChangeToInteger(s2);

            char s3[1001];
            inputbox_getline("Please enter the radius of the circle:", "", s3, 1000);
            int radius = ChangeToInteger(s3);

            char s4[1001];
            inputbox_getline("Please enter the framecolor:", "", s4, 1000);
            COLORS  framecolor = ChangeToColor(s4);

            char s5[1001];
            inputbox_getline("Please enter the backgoundcolor:", "", s5, 1000);
            COLORS backgroundcolor = ChangeToColor(s5);

            char s6[1001];
            inputbox_getline("Please enter the filledcolor:", "", s6, 1000);
            COLORS filledcolor = ChangeToColor(s6);

            char s7[1001];
            inputbox_getline("Filled or not?(yes/no)", "", s7, 1000);
            bool fil = ChangeToBool(s7);


            //����Բ��
            auto circleptr=new setCircle{ x,y,radius,framecolor,backgroundcolor,WHITE,filledcolor,fil };
            baseptr = circleptr;
            baseptr->draw();

            //ͣ��Ƭ��
            int a = getch();
            delete circleptr;
            //delete circleptr;
        }



        //������
        else if (s == "rectangle") {
            char s1[1001];
            inputbox_getline("Please enter the x coordinate of first point:", "", s1, 1000);
            int x1 = ChangeToInteger(s1);

            char s2[1001];
            inputbox_getline("Please enter the y coordinate of first point:", "", s2, 1000);
            int y1 = ChangeToInteger(s2);

            char s3[1001];
            inputbox_getline("Please enter the x cooradinate of second point", "", s3, 1000);
            int x2 = ChangeToInteger(s3);

            char s4[1001];
            inputbox_getline("Please enter the y coordinate of second point", "", s4, 1000);
            int y2 = ChangeToInteger(s4);


            char s5[1001];
            inputbox_getline("Please enter the framecolor:", "", s5, 1000);
            COLORS  framecolor = ChangeToColor(s5);

            char s6[1001];
            inputbox_getline("Please enter the backgoundcolor:", "", s6, 1000);
            COLORS backgroundcolor = ChangeToColor(s6);

            char s7[1001];
            inputbox_getline("Please enter the filledcolor:", "", s7, 1000);
            COLORS filledcolor = ChangeToColor(s7);

            char s8[1001];
            inputbox_getline("Filled or not?(yes/no)", "", s8, 1000);
            bool fil = ChangeToBool(s8);



            //��������
           
            auto rectangleptr=new setRectangle{ x1,y1,x2,y2,framecolor,backgroundcolor,WHITE,filledcolor,fil };
            baseptr = rectangleptr;
            baseptr->draw();

            //ͣ��Ƭ��
            int b=getch();
            delete rectangleptr;
        }



        //��������
        else if (s == "triangle") {
            char s1[1001];
            inputbox_getline("Please enter the x coordinate of first point:", "", s1, 1000);
            int x1 = ChangeToInteger(s1);

            char s2[1001];
            inputbox_getline("Please enter the y coordinate of first point:", "", s2, 1000);
            int y1 = ChangeToInteger(s2);

            char s3[1001];
            inputbox_getline("Please enter the x cooradinate of second point", "", s3, 1000);
            int x2 = ChangeToInteger(s3);

            char s4[1001];
            inputbox_getline("Please enter the y coordinate of second point", "", s4, 1000);
            int y2 = ChangeToInteger(s4);

            char s5[1001];
            inputbox_getline("Please enter the x cooradinate of third point", "", s5, 1000);
            int x3 = ChangeToInteger(s5);

            char s6[1001];
            inputbox_getline("Please enter the y coordinate of third point", "", s6, 1000);
            int y3 = ChangeToInteger(s6);

            char s7[1001];
            inputbox_getline("Please enter the framecolor:", "", s7, 1000);
            COLORS  framecolor = ChangeToColor(s7);

            char s8[1001];
            inputbox_getline("Please enter the backgoundcolor:", "", s8, 1000);
            COLORS backgroundcolor = ChangeToColor(s8);

            char s9[1001];
            inputbox_getline("Please enter the filledcolor:", "", s9, 1000);
            COLORS filledcolor = ChangeToColor(s9);

            char s10[1001];
            inputbox_getline("Filled or not?(yes/no)", "", s10, 1000);
            bool fil = ChangeToBool(s10);


            //����������
            auto triangleptr=new setTriangle{ x1,y1,x2,y2,x3,y3,framecolor,backgroundcolor,WHITE,filledcolor,fil };
            baseptr = triangleptr;
            baseptr->draw();

            //ͣ��Ƭ��
            getch();
            delete triangleptr;
        }

        baseptr=nullptr;

        //assert�Ƿ��������ͼ�δ���
        char str1[1001];
        inputbox_getline("Wanna continue to create?(yes/no)", "", str1, 1000);
        inputbox_getline("Wanna continue to create?(yes/no)", "", str1, 1000);
        if (ChangeToBool(str1)) {
            str[0] = '/';
            s = {};
        }
        else { break; }


    }









    getch();
    closegraph();
    return 0;
}