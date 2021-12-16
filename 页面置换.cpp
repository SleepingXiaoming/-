#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> Sequence{4, 3, 2, 1, 4, 3, 5, 4, 3, 2, 1, 5, 0}; //ҳ������
vector<int> opt;                                             // OPT�㷨����
int opt_count = 0;                                           // OPT�㷨ȱҳ����
vector<int> fifo;                                            // FIFO�㷨����
int fifo_count = 0;                                          // FIFO�㷨ȱҳ����
struct Lru
{
    int l;
    int times = 0;
};                                // LRU�ṹ��
vector<Lru> lru;                  // LRU�㷨����
int lru_count = 0;                // LRU�㷨ȱҳ����
bool check(vector<int> t, int i); //����i�Ƿ����������t֮��
void add(int temp);               // LRU��һ
bool cmp(Lru l1, Lru l2);         //��LRU�ṹ���������
void OPT(vector<int> sequence);   // OPT�㷨ʵ��
void FIFO(vector<int> sequence);  // FIFO�㷨ʵ��
void LRU(vector<int> sequence);   // LRU�㷨ʵ��
int main()
{
    cout << "OPT�㷨" << endl;
    OPT(Sequence);
    printf("OPT�㷨��ȱҳ��Ϊ:%.2lf%\n", opt_count * 100.0 / Sequence.size());
    cout << endl;

    cout << "FIFO�㷨" << endl;
    FIFO(Sequence);
    printf("FIFO�㷨��ȱҳ��Ϊ:%.2lf%\n", fifo_count * 100.0 / Sequence.size());
    cout << endl;

    cout << "LRU�㷨" << endl;
    LRU(Sequence);
    printf("LRU�㷨��ȱҳ��Ϊ:%.2lf%\n", lru_count * 100.0 / Sequence.size());
    return 0;
}

bool check(vector<int> t, int i)
{
    for (auto q : t)
    {
        if (q == i)
            return 1;
    }
    return 0;
}

bool cmp(Lru l1, Lru l2)
{
    return l1.times < l2.times;
}

void add(int temp)
{
    int l = lru.size();
    for (int i = 0; i < l; i++)
    {
        if (lru[i].l == temp)
            continue;
        lru[i].times++;
    }
}

void OPT(vector<int> sequence)
{
    int len = sequence.size();
    for (int i = 0; i < len; i++)
    {
        if (check(opt, sequence[i]))
            cout << "����" << endl;
        else if (opt.size() < 3)
        {
            cout << "����ȱҳ�жϣ�" << sequence[i] << "��ҳ������ڴ�" << endl;
            opt.push_back(sequence[i]);
            opt_count++;
        }
        else
        {
            vector<bool> temp(3, false);
            int c = 0;
            for (int j = i + 1; j < len; j++)
            {
                if (sequence[j] == opt[0])
                {
                    temp[0] = 1;
                    c++;
                }
                else if (sequence[j] == opt[1])
                {
                    temp[1] = 1;
                    c++;
                }
                else if (sequence[j] == opt[2])
                {
                    temp[2] = 1;
                    c++;
                }
                if (c == 2)
                    break;
            }
            for (int iw = 0; iw < 3; iw++)
            {
                if (!temp[iw])
                {
                    cout << "����ҳ���û�����" << sequence[i] << "��ҳ������ڴ棬" << opt[iw] << "ҳ������ڴ�" << endl;
                    opt[iw] = sequence[i];
                    opt_count++;
                    break;
                }
            }
        }
    }
}

void FIFO(vector<int> sequence)
{
    int len = sequence.size();
    for (int i = 0; i < len; i++)
    {
        if (check(fifo, sequence[i]))
            cout << "����" << endl;
        else if (fifo.size() < 3)
        {
            cout << "����ȱҳ�жϣ�" << sequence[i] << "��ҳ������ڴ�" << endl;
            fifo.push_back(sequence[i]);
            fifo_count++;
        }
        else
        {
            cout << "����ҳ���û�����" << sequence[i] << "��ҳ������ڴ棬" << fifo[0] << "ҳ������ڴ�" << endl;
            for (int w = 0; w < fifo.size() - 1; w++)
                fifo[w] = fifo[w + 1];
            fifo[fifo.size() - 1] = sequence[i];
            fifo_count++;
        }
    }
}

void LRU(vector<int> sequence)
{
    int len = sequence.size();
    for (int i = 0; i < len; i++)
    {
        int tag = 0; // cunzaifou
        for (int j = 0; j < lru.size(); j++)
            if (lru[j].l == sequence[i])
                tag = 1;
        if (tag)
        {
            cout << "����" << endl;
            // for (auto tt : lru)
            // {
            //     tt.times++;
            // }
            for (int tt = 0; tt < lru.size(); tt++)
                lru[tt].times++;
        }
        else if (lru.size() < 3)
        {
            cout << "����ȱҳ�жϣ�" << sequence[i] << "��ҳ������ڴ�" << endl;
            Lru tt;
            tt.l = sequence[i];
            lru.push_back(tt);
            add(sequence[i]);
            lru_count++;
        }
        else
        {
            sort(lru.begin(), lru.end(), cmp);
            cout << "����ҳ���û�����" << sequence[i] << "��ҳ������ڴ棬" << lru[2].l << "ҳ������ڴ�" << endl;
            lru[2].l = sequence[i];
            lru[2].times = 0;
            add(sequence[i]);
            lru_count++;
        }
    }
}