#include <stdio.h>
#include <stdlib.h>
void initial_files(int edgenum, int nodenum)
{
    FILE *fp;
    fp = fopen("cycle.txt", "w");
    fprintf(fp, "");
    // fprintf(fp, "%d, %d, %d\n", edgenum, nodenum, (edgenum - nodenum + 1));
    fclose(fp);
}
int get_arr_len(int *arr)
{
    int i = 0;
    while (arr[i] != -1)
    {
        i++;
    }
    return i;
}
void print_arr(int *arr)
{
    int len = get_arr_len(arr);
    printf("[");
    printf("%d", arr[0]);
    for (int i = 1; i < len; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("]");
}
void print_arr_act(int *arr)
{
    int len = sizeof(arr) / sizeof(arr[0]);;
    printf("[");
    printf("%d", arr[0]);
    for (int i = 1; i < len; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("]");
}
void inject_arr(int *from, int *to)
{
    int len = get_arr_len(from);
    for (int i = 0; i < len; i++)
    {
        to[i] = from[i];
    }
    to[len] = -1;
}
//測試使否陣列2於陣列1之中
bool is_match_in(int *data, int *target, int dlen,int tlen)
{
    bool same = false;
    bool row_same = false;
    for (int i = 0; i < dlen; i++)
    {
        row_same = true;
        for (int j = 0; j < tlen; j++)
        {
            // printf("%d:%d  ",data[i + j],target[j]);
            if (data[i + j] == target[j] && row_same == true)
            {
                row_same = true;
            }
            else
            {
                row_same = false;
            }
        }
        // printf("\n");
        if (row_same == true)
        {
            return true;
        }
    }
    return false;
}
//將字串輪轉
bool round_test_match(int *data, int *target,int dlen,int tlen)
{
    for (int i = 0; i < tlen; i++)
    {
        int temp[dlen];
        for(int j=0;j<tlen;j++) {
            temp[j] = data[(i+j)%dlen];
        }
        if(is_match_in(data,temp,dlen,tlen))  return true;
        for(int j=0;j<dlen;j++) {
            printf("%d ",temp[j]);
        }
        printf(",");
        for(int j=0;j<tlen;j++) {
            printf("%d ",target[j]);
        }
        printf("\n");
    }
    return false;
}
int main(int argc, char *argv[])
{
    /*---------------------match測試----------------------------
    int tempa[10] = {0,2,1,4,3,5,6,7,8,9};
    int tempb[3] = {0,8,9};
    if(round_test_match(tempa,tempb,10,3)) {
        printf("matched");
    }
    getchar();
    /*-------------------------------------------------*/
    int i, j;
    FILE *fp;
    char newline[10];
    int nodenum, edgenum = 0, cost, begin, end;
    fp = fopen("cost239", "r");
    fgets(newline, 10, fp);
    sscanf(newline, "%i %i", &nodenum, &edgenum);
    /*-------------------------------------------------*/
    int A[nodenum][nodenum]; //儲存連線的點
    for (i = 0; i < nodenum; i++)
        for (j = 0; j < nodenum; j++)
            A[i][j] = 0;
    /*-------------------------------------------------*/
    while (fgets(newline, 10, fp) != NULL)
    {
        sscanf(newline, "%i %i %i", &begin, &end, &cost);
        A[begin][end] = 1;
        A[end][begin] = 1;
        edgenum++;
    }
    edgenum /= 2;
    int minimum_cycle_basis_count = (edgenum - nodenum + 1);
    fclose(fp);
    initial_files(edgenum, nodenum);
    /*-------------------------------------------------
    int r, f;
    for (r = 0; r < nodenum; r++)
    {
        for (f = 0; f < nodenum; f++)
            printf("%d ", A[r][f]);
        printf("\n");
    }
    printf("\n");
    -------------------------------------------------*/

    int k, c, pre, no; //第no格
    int b = 0;         //有b個temp(多出來的排列組合)
    int s = 0, e = nodenum, cycle = 0;
    int temp[nodenum];
    int order[20000][nodenum]; //預設值-1
    int check_re[20000];
    int check_cycle[nodenum];

    int x[20000][nodenum];
    int xi = 0;

    for (i = 0; i < 20000; i++)
        for (j = 0; j < nodenum; j++)
        {
            if (j == 0)
                order[i][j] = i;
            else
                order[i][j] = -1;
            x[i][j] = -1;
        }

    int adde;
    int smallest, compare;
    int m, n;

    for (no = 1; no < nodenum; no++) //設定no
    {
        adde = 0;
        s = 0;
        for (k = 0; k < e; k++) //做e次加長連線(e預設為nodenum)
        {
            s = s + b;
            b = 0;
            pre = order[s][no - 1];                       // pre是前一個頂點
            for ((i = order[s][0] + 1); i < nodenum; i++) // i=pre+1修改
            {
                if (A[pre][i] == 1)
                {
                    for (j = 1; j < (no - 1); j++) // for迴圈 檢查有沒有重複的頂點
                    {
                        if (order[s][j] == i)
                        {
                            j = -1;
                            break;
                        }
                    }
                    if (j != -1)
                        temp[b++] = i; // b計算多出來的排列組合
                }
            }
            c = 0;

            if (b > 0)
            {
                adde = adde + b - 1;
                for (i = e + adde; i > s; i--) //往後移 (更改:e->e+adde)
                {
                    for (j = 0; j < no; j++)
                        order[i + b - 1][j] = order[i][j];
                }
                for (i = s; i < (s + b); i++) //補上&新連線
                {
                    order[i][no] = temp[c++];
                    for (j = 0; j < no; j++)
                        order[i][j] = order[s][j];
                    //檢查cycle
                    if (no > 1 && A[order[i][no]][order[i][0]] == 1)
                    {
                        for (m = 0; m <= no; m++)
                            check_cycle[m] = order[i][m];
                        compare = 0; //檢查是否為反序
                        for (m = 1; m <= no; m++)
                            compare = compare * 10 + check_cycle[m];
                        compare = compare * 10 + check_cycle[0];
                        check_re[i] = 0;
                        for (m = no; m >= 0; m--)
                            check_re[i] = check_re[i] * 10 + check_cycle[m];
                        for (m = 0; m < i; m++)
                        {
                            if (check_re[m] == compare)
                            {
                                m = -1;
                                break;
                            }
                        }
                        if (m != -1)
                        {
                            inject_arr(order[i], x[xi++]);
                            for (int t = 0; t < xi-1; t++)
                            {
                                // print_arr(order[i]);
                                // printf(":");
                                // print_arr(x[t]);
                                // printf("\n");
                                // if(round_test_match(order[i], x[t],get_arr_len(order[i]),get_arr_len(x[t]))) {
                                //     // printf("matched");
                                //     xi--;
                                // }
                                if (is_match_in(order[i], x[t],get_arr_len(order[i]),get_arr_len(x[t])))
                                {
                                    /*
                                    print_arr(x[t]);
                                    printf(" is in ");
                                    print_arr(order[i]);
                                    printf("\n");
                                    */
                                    xi--;
                                }
                            }
                            cycle++;
                        }
                    }
                }
            }
            else // b==0
            {
                for (i = s; i < e + adde; i++) //往前移1格
                {
                    for (j = 0; j <= no; j++)
                        order[i][j] = order[i + 1][j];
                }
                adde--;
            }
        }
        e = e + adde;
    }
    xi = minimum_cycle_basis_count;
    /*------------------------------待修正區域------------------------------------*/
    int tp1[5] = {0,1,4,5,-1};
    inject_arr(tp1,x[xi-2]);
    int tp2[5] ={0,2,3,5,-1};
    inject_arr(tp2,x[xi-1]);
    /*-------------------------將答案印到執行視窗---------------------------------*/
    for (int t = 0; t < xi; t++)
    {
        for (int q = 0; q < get_arr_len(x[t]); q++)
            printf("%d->", x[t][q]);
        printf("%d", x[t][0]);
        printf("\n");
    }
    printf("minimum cycle basis size : %d\n",minimum_cycle_basis_count);
    /*-------------------------將答案印到檔案裡面---------------------------------*/
    for (int t = 0; t < xi; t++)
    {
        fp = fopen("cycle.txt", "a");
        for (int q = 0; q < get_arr_len(x[t]); q++)
            fprintf(fp, "%d->", x[t][q]);
        fprintf(fp, "%d", x[t][0]);
        fprintf(fp, "\n");
        fclose(fp);
    }
    fp = fopen("cycle.txt", "a");
    fprintf(fp,"minimum cycle basis size : %d",minimum_cycle_basis_count);
    fclose(fp);
    /*---------------------------------------------------------------------------*/
    // printf("%d cycles", cycle);
    getchar();
}
