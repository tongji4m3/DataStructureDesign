#ifndef _SORT_COMPARE_
#define _SORT_COMPARE_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SortCompare
{
public:
    SortCompare(int N)
    {
        //每一次运行程序产生了同样的随机数,所以可以重复验证
        //默认的0-65535就够了
        for (int i = 0; i < N; ++i)
        {
            vec.push_back(rand());
        }

    }

    void test(int whichSort, double &sortTime, long long &exchangeTime)
    {

        clock_t start = clock();
        switch (whichSort)
        {
            case 1:
                bubbleSort(exchangeTime);
                break;
            case 2:
                chooseSort(exchangeTime);
                break;
            case 3:
                insertSort(exchangeTime);
                break;
            case 4:
                shellSort(exchangeTime);
                break;
            case 5:
                quickSort(exchangeTime);
                break;
            case 6:
                heapSort(exchangeTime);
                break;
            case 7:
                mergeSort(exchangeTime);
                break;
            case 8:
                radixSort(exchangeTime);
                break;
            default:
                break;
        }
        clock_t end = clock();
        sortTime = (double) (end - start) / CLOCKS_PER_SEC;
    }

private:
    //每一次排序都把原始数据复制一遍,保证了原始数据是不变的,
    //可以更好的对比性能
    void bubbleSort(long long &exchangeTime) 
    {
        vector<int> temp(vec);
        //每次都把最小的排定
        for (int i = 1; i < temp.size(); ++i)
        {
            for (int j = temp.size() - 1; j >= i; --j)
            {
                if (temp[j - 1] > temp[j])
                {
                    exch(temp, j, j - 1);
                    ++exchangeTime;
                }
            }
        }
        if (!isSorted(temp))
        {
            cout << "没排序!" << endl;
        }
    }

    void chooseSort(long long &exchangeTime)
    {
        vector<int> temp(vec);
        for (int i = 0; i < temp.size() - 1; ++i)
        {
            int min = i;
            for (int j = i + 1; j < temp.size(); ++j)
            {
                if (temp[min] > temp[j])
                {
                    min = j;
                }
            }
            exch(temp, min, i);
            ++exchangeTime;
        }
        if (!isSorted(temp))
        {
            cout << "没排序!" << endl;
        }
    }

    void insertSort(long long &exchangeTime)
    {
        vector<int> temp(vec);
        for (int i = 1; i < temp.size(); ++i)
        {
            for (int j = i; j - 1 >= 0 && temp[j] < temp[j - 1]; --j)
            {
                exch(temp, j - 1, j);
                ++exchangeTime;
            }
        }
        if (!isSorted(temp))
        {
            cout << "没排序!" << endl;
        }
    }

    void shellSort(long long &exchangeTime)
    {
        vector<int> temp(vec);


        int h = 1;
        while (h < temp.size() / 3)
        {
            h = 3 * h + 1;
        }

        while (h >= 1)
        {
            for (int i = h; i < temp.size(); ++i)
            {
                for (int j = i; j - h >= 0 && temp[j] < temp[j - h]; j -= h)
                {
                    exch(temp, j - h, j);
                    ++exchangeTime;
                }
            }
            h /= 3;
        }

        if (!isSorted(temp))
        {
            cout << "没排序!" << endl;
        }
    }

    int partition(vector<int> &temp, int lo, int hi, long long &exchangeTime)
    {
        int i = lo, j = hi + 1;
        int v = temp[lo];
        while (true)
        {
            while (temp[++i] < v) if (i == hi) break;
            while (v < temp[--j]) if (j == lo) break;
            if (i >= j)
                break;
            exch(temp, i, j);
            ++exchangeTime;
        }
        exch(temp, lo, j);
        ++exchangeTime;
        return j;
    }

    void quickSort(vector<int> &temp, int lo, int hi, long long &exchangeTime)
    {
        if (hi <= lo)
        {
            return;
        }
        int j = partition(temp, lo, hi, exchangeTime);
        quickSort(temp, lo, j - 1, exchangeTime);
        quickSort(temp, j + 1, hi, exchangeTime);
    }

    void quickSort(long long &exchangeTime)
    {
        vector<int> temp(vec);

        //因为本来就是乱的,所以不用打乱了
        quickSort(temp, 0, temp.size() - 1, exchangeTime);

        if (!isSorted(temp))
        {
            cout << "没排序!" << endl;
        }
    }

    void sink(vector<int> &temp, int k, int N, long long &exchangeTime)
    {
        while(2*k<=N)
        {
            int j = 2 * k;
            if(j+1<=N && temp[j+1]>temp[j])
            {
                ++j;
            }
            if(temp[k]>temp[j])
            {
                break;
            }
            exch(temp, k, j);
            k = j;
            ++exchangeTime;
        }
    }

    void heapSort(long long &exchangeTime)
    {
        vector<int> temp(vec);
        int N = temp.size();
        temp.insert(temp.begin(), -1);//temp[0]不用
        //构造堆
        for (int k = N/2; k >= 1 ; --k)
        {
            sink(temp, k, N,exchangeTime);
        }
        //排序
        while(N>1)
        {
            exch(temp, 1, N--);
            ++exchangeTime;
            sink(temp, 1, N,exchangeTime);
        }


        if (!isSorted(temp))
        {
            cout << "没排序!" << endl;
        }
    }

    void merge(vector<int> &temp, vector<int> &aux, int lo, int mid, int hi, long long &exchangeTime)
    {
        //mid左右两边已经拍好了序
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; ++k)
        {
            aux[k] = temp[k];
        }
        for (int k = lo; k <= hi; ++k)
        {
            //上面两个不进行比较
            if (i > mid) temp[k] = aux[j++];
            else if (j > hi) temp[k] = aux[i++];
            else if (aux[j] < aux[i])
            {
                temp[k] = aux[j++];
                ++exchangeTime;
            }
            else
            {
                temp[k] = aux[i++];
                ++exchangeTime;
            }
        }
    }

    void mergeSort(vector<int> &temp, vector<int> &aux, int lo, int hi, long long &exchangeTime)
    {
        if (hi <= lo)
        {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        mergeSort(temp, aux, lo, mid, exchangeTime);
        mergeSort(temp, aux, mid + 1, hi, exchangeTime);

        merge(temp, aux, lo, mid, hi, exchangeTime);

    }

    void mergeSort(long long &exchangeTime)
    {
        vector<int> temp(vec);

        vector<int> aux(vec.size());//辅助数组

        mergeSort(temp, aux, 0, temp.size() - 1, exchangeTime);

        if (!isSorted(temp))
        {
            cout << "没排序!" << endl;
        }
    }

    int getDigit(const vector<int> & temp)
    {
        int digit = 1;
        int base = 10;
        for (int i = 0; i < temp.size(); ++i)
        {
            while(base<=temp[i])
            {
                base *= 10;
                ++digit;
            }
        }
        return digit;
    }
    //实际上就是低位优先的字符串排序
    void radixSort(long long &exchangeTime)
    {
        vector<int> temp(vec);

        vector<int> aux(temp);

        int N = temp.size();
        int R = 10;//一共只有0-9
        int digit = getDigit(temp);
        int base = 1;//目的是得到一个数的某一位的数,如得到123中的2
        //0表示个位
        for (int d = 0; d < digit; ++d)
        {
            vector<int> count(R + 1);//计算出现的频率
            for (int i = 0; i < N; ++i)
            {
                //就算有一些的位数不够也没有关系,因为这样会是0,还是会排序
                int index = temp[i] / base % 10;//第一次得到是个位,第二次是十位..
                count[index + 1]++;
            }
            for (int r = 0; r < R; ++r)//将频率转换为索引
            {
                count[r + 1] += count[r];
            }
            for (int i = 0; i < N; ++i)//将元素分类
            {
                int index = temp[i] / base % 10;
                aux[count[index]++] = temp[i];
            }
            for (int i = 0; i < N; ++i)//回写
            {
                temp[i] = aux[i];
            }
            base *= 10;//不断处理高位
        }



        if (!isSorted(temp))
        {
            cout << "没排序!" << endl;
        }
    }


    bool isSorted(vector<int> &cur)
    {
        for (int i = 0; i < cur.size() - 1; ++i)
        {
            if (cur[i + 1] < cur[i])
            {
                return false;
            }
        }
        return true;
    }

    void exch(vector<int> &cur, int i, int j)
    {
        int temp = cur[i];
        cur[i] = cur[j];
        cur[j] = temp;
    }

    vector<int> vec;
};

#endif //_SORT_COMPARE_
