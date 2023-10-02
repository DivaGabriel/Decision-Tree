#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;
/*
1 1000 600 F 1 40 5 50000 1 1 0 100000
1 1000 800 F 1 30 3 100000 2 0 0 100000
1 1000 600 S 0 45 6 120000 3 1 1 130000
1 1000 400 G 1 60 9 140000 4 1 0 160000
*/
double n;              // n :訓練測資量
int table[2][2] = {0}; //實際1/0 猜測1/0
struct Data
{
    int customer_id = 0;
    int credit_score = 0;
    string country;
    bool gender; // 0:男 1:女
    int age;
    int tenure;
    float balance;
    int products_number;
    int credit_card;   //好像只有0,1
    int active_member; //好像只有0,1
    double estimated_salary;
    bool answer; // answer = churn
};
class Node
{
public:
    Node()
    {
        leftchild = NULL;
        rightchild = NULL;
        next = NULL;
    }
    Node *getleft()
    {
        return leftchild;
    }
    Node *getright()
    {
        return rightchild;
    }
    void SetData(int atnumber, double p1, char c1)
    {
        for (int i = 0; i < depth; i++)
        {
            cout << "\t";
        }
        cout << "開始分類" << endl;
        attribute = atnumber;
        cout << "第 " << attribute << "個屬性" << endl;
        int pcount1 = 0, pcount2 = 0;
        leftchild = new Node;
        rightchild = new Node;
        leftchild->depth = depth + 1;
        rightchild->depth = depth + 1;
        leftchild->setdepth();
        rightchild->setdepth();
        hasused[attribute] = true;
        for (int i = 1; i < 12; i++)
        {
            leftchild->hasused[i] = hasused[i];
            rightchild->hasused[i] = hasused[i];
        }
        yestotal = 0;
        nototal = 0;
        if (attribute == 2)
        {
            cutchar = c1;
            classificaction = 1;

            cout << "以 " << cutchar << "作為分類標準" << endl;
            for (int i = 0; i < total; i++)
            {
                if (data[i].country[0] == cutchar)
                {
                    leftchild->data[pcount1] = data[i];
                    if (data[i].answer)
                    {
                        leftchild->yestotal += 1;
                    }
                    else
                    {
                        leftchild->nototal += 1;
                    }
                    pcount1++;
                }
                else
                {
                    rightchild->data[pcount2] = data[i];
                    if (data[i].answer)
                    {
                        rightchild->yestotal += 1;
                    }
                    else
                    {
                        rightchild->nototal += 1;
                    }
                    pcount2++;
                }
            }
            leftchild->total = pcount1;
            rightchild->total = pcount2;
        }
        else
        {
            cutnumber = p1;
            classificaction = 0;
            cout << "以 " << cutnumber << "作為分類標準" << endl;
            for (int i = 0; i < total; i++)
            {
                switch (attribute)
                {
                case 1:
                    if (data[i].credit_score <= cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                        pcount1++;
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                case 3:
                    if (data[i].gender == cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        pcount1++;
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                case 4:
                    if (data[i].age <= cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        pcount1++;
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                case 5:
                    if (data[i].tenure <= cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        pcount1++;
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                case 6:
                    if (data[i].balance <= cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        pcount1++;
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                case 7:
                    if (data[i].products_number <= cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        pcount1++;
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                case 8:
                    if (data[i].credit_card == cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        pcount1++;
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                case 9:
                    if (data[i].active_member == cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        pcount1++;
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                case 10:
                    if (data[i].estimated_salary <= cutnumber)
                    {
                        leftchild->data[pcount1] = data[i];
                        if (data[i].answer)
                        {
                            leftchild->yestotal += 1;
                        }
                        else
                        {
                            leftchild->nototal += 1;
                        }
                        pcount1++;
                    }
                    else
                    {
                        rightchild->data[pcount2] = data[i];
                        pcount2++;
                        if (data[i].answer)
                        {
                            rightchild->yestotal += 1;
                        }
                        else
                        {
                            rightchild->nototal += 1;
                        }
                    }
                    break;
                }
            }
            leftchild->total = pcount1;
            rightchild->total = pcount2;
        }
    }
    bool dsffind(Data d)
    {
        if (leaf)
        {
            return finalanswer;
        }
        else
        {
            if (attribute == 2)
            {
                if (d.country[0] == cutchar)
                {
                    //往左下
                    return leftchild->dsffind(d);
                }
                else
                {
                    return rightchild->dsffind(d);
                }
            }
            else
            {
                //數值型
                switch (attribute)
                {
                case 1:
                    if (d.credit_score <= cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                case 3:
                    if (d.gender == cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                case 4:
                    if (d.age <= cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                case 5:
                    if (d.tenure <= cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                case 6:
                    if (d.balance <= cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                case 7:
                    if (d.products_number <= cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                case 8:
                    if (d.credit_card == cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                case 9:
                    if (d.active_member == cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                case 10:
                    if (d.estimated_salary <= cutnumber)
                    {
                        return leftchild->dsffind(d);
                    }
                    else
                    {
                        return rightchild->dsffind(d);
                    }
                    break;
                }
            }
        }
    }
    int testingdata()
    {
        //理論上只有root會觸發
        yestotal = 0, nototal = 0;
        int current = 0;
        for (int i = n; i < 10000; i++)
        {
            if (dsffind(data[i]))
            { //猜1
                if (data[i].answer)
                {
                    //實1猜1
                    yestotal++;
                    current++;
                    table[0][0]++;
                }
                else
                {
                    //實0猜1
                    nototal++;
                    table[1][0]++;
                }
            }
            else
            { //猜0
                if (data[i].answer)
                {
                    //實1猜0
                    yestotal++;
                    table[0][1]++;
                }
                else
                {
                    //實0猜0
                    nototal++;
                    table[1][1]++;
                    current++;
                }
            }
        }
        return current;
    }
    void leafset(bool A)
    {
        //整齊了
        leaf = true;
        finalanswer = A;
    }
    void leafset()
    {
        //過深了
        leaf = true;
        if (yestotal >= nototal)
        {
            finalanswer = true;
        }
        else
        {
            finalanswer = false;
        }
    }
    void setdepth()
    {
        depth = depth + 1;
    }
    int getdepth()
    {
        return depth;
    }
    double total = 0;
    double yestotal = 0;
    double nototal = 0;
    Data data[10002];
    Node *next;
    bool hasused[12] = {0};

private:
    Node *leftchild, *rightchild;
    int depth = 0;
    int attribute;
    bool classificaction; // 0 = 數值型 1 = 非數值型(only country)
    double cutnumber;
    char cutchar;
    bool leaf = false;
    bool finalanswer;
};

class Queue
{
public:
    Queue()
    {
        Size = 0;
        head = NULL;
        tail = NULL;
    }
    void Push(Node *node)
    {
        if (Size == 0)
        {
            head = node;
            tail = node;
            head->next = NULL;
        }
        else if (Size == 1)
        {
            tail = node;
            head->next = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        tail->next = NULL;
        Size++;
    }
    void Pop()
    {
        if (Size > 2)
        {
            head = head->next;
        }
        else if (Size == 2)
        {
            head = tail;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        Size--;
    }
    bool Empty()
    {
        if (Size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Node *Front() const
    {
        return head;
    }

private:
    Node *head;
    Node *tail;
    int Size;
};

ostream &operator<<(ostream &os, const Data &dt)
{
    os << "customer_id = " << dt.customer_id << endl
       << "credit_score = " << dt.credit_score << endl
       << "country = " << dt.country << endl
       << "gender = " << dt.gender << endl
       << "age = " << dt.age << endl
       << "tenure = " << dt.tenure << endl
       << fixed << setprecision(2) << "balance = " << dt.balance << endl
       << "products_number = " << dt.products_number << endl
       << "credit_card = " << dt.credit_card << endl
       << "active_member = " << dt.active_member << endl
       << fixed << setprecision(2) << "estimated_salary = " << dt.estimated_salary << endl
       << "answer = " << dt.answer << endl;

    return os;
}
int main()
{
    string pstring;
    char pchar[20] = "testnumber";
    Node *root = new Node;
    int maxdepth;
    cout << "以Decision Tree加Grin index 來做分類"
         << "\n請輸入最深分層深度(>=1,請不要輸太高 會炸)(leaf將以多數決決定label是 1 or 0): ";
    cin >> maxdepth;
    cout << "請輸入要用前多少筆資料訓練測資:";
    cin >> n;
    Queue tree;
    double tmp_dou;
    // Data customer[10000];
    int cut_sum = 0;
    int tmp_int;
    ifstream file;
    file.open("Bank_Customer.csv");
    // file.open("testt.csv");
    string line;
    string tmp[5][5];
    char ch = '"';
    string::iterator it;
    int sum = 0;
    int now_data;
    while (getline(file, line, '\n')) //讀檔讀到跳行字元
    {
        if (sum == 0)
        {
            sum++;
            continue;
        }
        sum++;
        istringstream templine(line); // string 轉換成 stream
        string data;
        now_data = 0;
        while (getline(templine, data, ',')) //讀檔讀到逗號
        {
            for (it = data.begin(); it < data.end(); it++)
            {
                if (*it == ch)
                {
                    data.erase(it);
                    it--;
                }
            }
            // tmp_int = stoi(data);
            // cout << tmp_int << " ";
            now_data++;
            if (now_data == 1)
            {
                (*root).data[cut_sum].customer_id = stoi(data);
                // cout << customer[0].customer_id << "**";
                continue;
            }

            else if (now_data == 2)
            {
                (*root).data[cut_sum].credit_score = stoi(data);
                continue;
            }

            else if (now_data == 3)
            {
                (*root).data[cut_sum].country = data;
                continue;
            }
            else if (now_data == 4)
            {
                if (data == "Female")
                    (*root).data[cut_sum].gender = 1;
                else if (data == "Male")
                    (*root).data[cut_sum].gender = 0;
                continue;
            }
            else if (now_data == 5)
            {
                (*root).data[cut_sum].age = stoi(data);
                continue;
            }
            else if (now_data == 6)
            {
                (*root).data[cut_sum].tenure = stoi(data);
                continue;
            }
            else if (now_data == 7)
            {
                (*root).data[cut_sum].balance = stof(data);
                continue;
            }
            else if (now_data == 8)
            {
                (*root).data[cut_sum].products_number = stoi(data);
                continue;
            }
            else if (now_data == 9)
            {
                (*root).data[cut_sum].credit_card = stoi(data);
                continue;
            }
            else if (now_data == 10)
            {
                (*root).data[cut_sum].active_member = stoi(data);
                continue;
            }
            else if (now_data == 11)
            {
                (*root).data[cut_sum].estimated_salary = stof(data);
                continue;
            }
            else if (now_data == 12)
            {
                (*root).data[cut_sum].answer = stoi(data);
                if ((*root).data[cut_sum].answer)
                {
                    root->yestotal++;
                }
                else
                {
                    root->nototal++;
                }
                continue;
            }
        }
        cut_sum++;
    }
    // cout<<(*root).data[0];
    root->total = n;
    file.close();
    tree.Push(root);
    // cout<<(*tree.Front()).data[0];
    double cutnumber[12];
    char cp;
    int resetbool = 0;

    while (tree.Front()->getdepth() <= maxdepth)
    {
        Node *tnode = tree.Front();
        if (tnode->getdepth() == resetbool)
        {
            cout << "第 " << resetbool << " 層" << endl;
            cout << "輸入各屬性分隔(數值<=,> or 國家第一個字 or 1或0): " << endl;
            for (int i = 1; i < 11; i++)
            {
                cout << "第 " << i << " 個屬性: ";
                tnode->hasused[i] = false;
                if (i == 2)
                {
                    cin >> cp;
                    cp = toupper(cp);
                    // cout<<cp;
                }
                else
                {
                    cin >> cutnumber[i];
                    // cout<<cutnumber[i];
                }
                // cout<<endl;
            }
            resetbool += 10; //每10層重新輸入一次分類
        }
        tree.Pop();
        if (tnode->yestotal == 0 || tnode->nototal == tnode->total)
        {
            tnode->leafset(false);
            continue;
        }
        else if (tnode->yestotal == tnode->total || tnode->nototal == 0)
        {
            tnode->leafset(true);
            continue;
        }
        double gini[12] = {0};
        double lowgini = 1;
        int lowtag = 0;
        double t1[12][2] = {0}, t2[12][2] = {0}; // t1[][0]記符合的量 t1[][1]記符合且對的量  t2[][0]記 不符合的量 t2[][1]記符合且對的量
        for (int i = 0; i < tnode->total; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                if (tnode->hasused[j])
                {
                    continue;
                }
                switch (j)
                {
                case 1:
                    if ((*tnode).data[i].credit_score <= cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 2:
                    if ((*tnode).data[i].country[0] == cp)
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 3:
                    if ((*tnode).data[i].gender == cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 4:
                    if ((*tnode).data[i].age <= cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 5:
                    if ((*tnode).data[i].tenure <= cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 6:
                    if ((*tnode).data[i].balance <= cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 7:
                    if ((*tnode).data[i].products_number <= cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 8:
                    if ((*tnode).data[i].credit_card == cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 9:
                    if ((*tnode).data[i].active_member == cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                case 10:
                    if ((*tnode).data[i].estimated_salary <= cutnumber[j])
                    {
                        t1[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t1[j][1] += 1;
                        }
                    }
                    else
                    {
                        t2[j][0] += 1;
                        if ((*tnode).data[i].answer == 1)
                        {
                            t2[j][1] += 1;
                        }
                    }
                    break;
                }
            }
        }
        /* for(int i=1; i<11; i++)
         {
             cout<<"  符合的量: "<<t1[i][0]<<" 其中為true的量: "<<t1[i][1]<<endl;
             cout<<"不符合的量: "<<t2[i][0]<<" 其中為true的量: "<<t2[i][1]<<endl;
         }*/
        for (int i = 1; i < 11; i++)
        {
            // if(t1[i][0] == t1[i])
            // cout<<t1[i][0]/tnode->total<<" "<<(t1[i][1]/t1[i][0]*t1[i][1]/t1[i][0])<<" "<<((t1[i][0]-t1[i][1]) / t1[i][0] * (t1[i][0]-t1[i][1]) / t1[i][0])<<endl;
            // cout<<t2[i][0]/tnode->total<<" "<<(t2[i][1]/t2[i][0]*t2[i][1]/t2[i][0])<<" "<<((t2[i][0]-t2[i][1]) / t2[i][0] * (t2[i][0]-t2[i][1]) / t2[i][0])<<endl;
            gini[i] = (t1[i][0] / tnode->total) * (1.0 - (t1[i][1] / t1[i][0] * t1[i][1] / t1[i][0]) - ((t1[i][0] - t1[i][1]) / t1[i][0] * (t1[i][0] - t1[i][1]) / t1[i][0])) +
                      (t2[i][0] / tnode->total) * (1.0 - (t2[i][1] / t2[i][0] * t2[i][1] / t2[i][0]) - ((t2[i][0] - t2[i][1]) / t2[i][0] * (t2[i][0] - t2[i][1]) / t2[i][0]));
            if (gini[i] < lowgini)
            {
                lowgini = gini[i];
                lowtag = i;
            }
            // cout<<"i:"<<i<<" gini: "<<gini[i]<<endl;
        }
        // cout<<"\n\n\n"<<endl;
        // cout<<cutnumber[lowtag]<<endl;
        tnode->SetData(lowtag, cutnumber[lowtag], cp);
        // cout<<"分類完成"<<endl;
        tree.Push(tnode->getleft());
        tree.Push(tnode->getright());
        // cout<<"進入下一輪循環"<<endl;
        /*if(p == 2)
        {
            cin>>cp;
            tnode.SetData(p,1,0,cp);
        }
        else if(p >=1 && p<=10)
        {
             cin>>cutnumber;
             tnode.SetData(p,0,cutnumber,'a');
        }
        else
        {
            cout<<"無此屬性"<<endl;
            return 0;
        }*/
    }
    while (!tree.Empty())
    {
        Node *tnode = tree.Front();
        tree.Pop();
        tnode->leafset();
    }
    int corrent = root->testingdata();
    // cout<<"左側樹為true的量: "<<root->getleft()->yestotal<<" 為false的量: "<<root->getleft()->nototal<<" 不會離開的占比: "<<double((root->getleft()->nototal)/(root->getleft()->nototal+root->getleft()->yestotal))<<endl;
    // cout<<"右側樹為true的量: "<<root->getright()->yestotal<<" 為false的量: "<<root->getright()->nototal<<" 不會離開的占比: "<<double((root->getright()->nototal)/(root->getright()->nototal+root->getright()->yestotal))<<endl;
    cout << "預測命中次數: " << corrent << " \n 預測命中機率 : " << double(corrent / (10000 - n)) << endl;
    cout << "預測失敗次數: " << 10000 - n - corrent << " \n 預測失敗機率 : " << double((10000 - n - corrent) / (10000 - n)) << endl;
    cout << "測資為true的量: " << root->yestotal << " 測資為false的量: " << root->nototal << endl;
    cout << "實1猜1: " << table[0][0] << " 實0猜1: " << table[1][0] << endl;
    cout << "實1猜0: " << table[0][1] << " 實0猜0: " << table[1][1] << endl;
    /*gini[0]=1-(t1[10]/n*t1[10]/n)-(t2[10]/n*t2[10]/n);
    cout<<gini[0];*/
    /* for(int i=0;i<10;i++)
     {
         cout<<data[i].customer_id<<" "<<data[i].credit_score<<" "<<pchar[0]<<" "<<pchar[1]<<" "<<data[i].age<<" "<<data[i].tenure<<" "<<data[i].balance<<" "<<data[i].products_number<<" "<<data[i].credit_card<<" "
         <<data[i].active_member<<" ";
         cout<<fixed<<setprecision(4)<<data[i].estimated_salary<<" "<<data[i].answer<<endl;
     }*/
    return 0;
}
