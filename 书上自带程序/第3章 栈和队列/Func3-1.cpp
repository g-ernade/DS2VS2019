 // func3-1.cpp algo3-5.cpp��algo3-6.cppҪ���õĺ���
 char Precede(SElemType t1,SElemType t2)
 { // ���ݽ̿����3.1���ж�t1��t2�����ŵ����ȹ�ϵ('#'��'\n'����)
   char f;
   switch(t2)
   { case '+':
     case '-':if(t1=='('||t1=='\n')
                f='<'; // t1<t2
              else
                f='>'; // t1>t2
              break;
     case '*':
     case '/':if(t1=='*'||t1=='/'||t1==')')
                f='>'; // t1>t2
              else
                f='<'; // t1<t2
              break;
     case '(':if(t1==')')
              { printf("���Ų�ƥ��\n");
                exit(OVERFLOW);
              }
              else
                f='<'; // t1<t2
              break;
     case ')':switch(t1)
              { case '(':f='='; // t1=t2
                         break;
                case'\n':printf("ȱ��������\n");
                         exit(OVERFLOW);
                default :f='>'; // t1>t2
              }
              break;
     case'\n':switch(t1)
              { case'\n':f='='; // t1=t2
                         break;
                case '(':printf("ȱ��������\n");
                         exit(OVERFLOW);
                default :f='>'; // t1>t2
              }
   }
   return f;
 }

 Status In(SElemType c)
 { // �ж�c�Ƿ�Ϊ7�������֮һ
   switch(c)
   { case '+':
     case '-':
     case '*':
     case '/':
     case '(':
     case ')':
     case'\n':return TRUE;
     default :return FALSE;
   }
 }

 SElemType Operate(SElemType a,SElemType theta,SElemType b)
 { // ����������a theta b������������
   switch(theta)
   { case'+':return a+b;
     case'-':return a-b;
     case'*':return a*b;
   }
   return a/b;
 }
