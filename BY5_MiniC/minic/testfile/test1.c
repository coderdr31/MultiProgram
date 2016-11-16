int main(void)
{
    int i;   // i 的声明，控制执行次数
    int value; /*value 的声明，
    加减乘除运算后的结果*/
    i = 0; value = 100;
    while (i <= 2) {
        output(value);
        value = value / 2;        
        i = i + 1;
    }
    return 0;
}
