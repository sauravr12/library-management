#include<iostream>
#include<conio>
#include<fstream>
using namespace std;
class student
{
    char name[20];
    int r;
public:
    void input()
    {
        cout<<"roll=";
        cin>>r;
        cout<<"name=";
        cin>>name;

    }
    void output()
    {
        cout<<"roll=="<<r;
        cout<<"name=="<<name;
    }
};
void write2file()
{
    ofstream outfile("text.txt",ios::binary||ios::app);
    student s;
    s.input();
    outfile.write(reinterpret_cast<char*>(&s),sizeof(s));
}
void read2file()
{
   ifstream infile("text.txt",ios::binary);
   while(!infile.eof())
   {
       if(infile.read(reinterpret_cast<char*>(&s),sizeof(s)>0))
       {
           student s;
           s.output();
       }
   }
}
int main()
{
    write2file();
    read2file();
    getch();
    return 0:
}
