#include <iostream>
using namespace std;

#define DAY 7
int main() {

    cout << "�����BB" << endl;
    char c[] = "Hello World ����";
    string str = "First blood";

    bool ok = false;
    bool is_ok = true;
    cout << ok << endl;
    cout << is_ok << endl;

    cout << str << endl;
    cout << c << endl;

    int a = 0;
    //���ȥ������̨(output)
    cout << "����������:" << endl;
    //��������(input)
    //cin >> a ;
    cout << a << endl;
    a = 1 | 1;
    cout << a << endl;
    a = 1 & 2;
    cout << a << endl;

    if (a > 0) {
        cout << "1" << endl;
    } else if (a == 0) {
        cout << "<0 " << endl;
    } else {
        cout << "error" << endl;
    }


    int k, g = 0;
    k = 10;

    (k > g ? k : g) = 1000;
    cout << k << endl;


    switch (a) {
        case 1:
            cout << 1 << endl;
            break;
        case 2:
            cout << 2 << endl;
            break;
        default:
            cout << "default" << endl;
            break;
    }

    for (;;) {
        a++;
        if (a % 2 == 0) {
            //continue;
            break;
        }
        cout << a << endl;
    }

    //����goto,��ôֱ��������ǵ�λ��
    goto LOOP;
    //��ִ��
    cout << 222 << endl;
    LOOP:
    cout << 333 << endl;

    int arr[] = {1, 2, 3};
    cout << sizeof(arr) << endl;

    for (int i = 0; i < 3; ++i) {
        cout << arr[i] << endl;
    }
    //�׸�Ԫ�ص�ַ(16����)
    cout << arr << endl;
    //����0�ĵ�ַ
    cout << &arr[0] << endl;

    int param = 10;
    //����һ��ָ��
    int * p;
    p = &param;
    //��ӡָ���ַ
    cout << &a << endl;
    cout << p << endl;

    //������
    cout << *p << endl;
    //ͨ��ָ��ȥ��������(�ı����param����)
    *p = 666;
    /**
     * ��32λ����ϵͳ��,ָ�붼��ռ��4λ
     * ��64λ����ϵͳ��,ָ��ռ��8λ
     */
    cout << *p << endl;
    cout << param << endl;

    /**
     * ��ָ��
     * ��ָ���ǲ��ܽ��з��ʵ�
     * 0~255֮����ڴ�����ϵͳʹ�õ�,��˲��ܷ���
     */
    int * pp = NULL;
    //����,�߲���ȥ��
    //cout << *pp << endl;

    /**
     * Ұָ��: ָ��һ��Խ��ĵ�ַ
     */
    int * y = (int *) 0x11111;
    // ����,ָ��Խ��,�Ƿ�ָ��
   // cout << *y << endl;

    /**
     * 1.����ָ��:
     *   ָ������޸�ָ��,
     *   ���ǲ����޸�ָ���ֵ
     */
    int cc = 6;
    int bb = 7;
    const int * cl = &cc;
    //����
    cl = &bb;
    //�Ƿ�: *cl = 8888;

    /**
     * 2.ָ�볣��:
     *  ָ�벻���޸�
     *  ָ��ָ���ֵ�����޸�
     */
    int * const zz = &cc;
    // ����,�����޸�ָ�� zz = &bb;
    //��ȷ ,�����޸�ָ��ָ�������
    *zz = 999;

    /**
     * 3. const������ָ�������γ���
     * �������޸�ָ��ֵ�ֲ����޸�ָ��
     */
     const int * const ff = &cc;

     /**
      * ʹ��ָ��ȥ��������
      */
      int arrayNum [] = {11,22,33};
      int * pArray = arrayNum;
      // ��ӡ����Ϊ0��ֵ
      cout << *pArray << endl;

      //ָ�����ƫ��4���ֽ�(��Ϊ�������int����)
      pArray++;
      //��ʱ���ӡ�ľ�������Ϊ1��ֵ
      cout << *pArray << endl;

      int num = 5;
      while (num -- > 0){
          cout << num << endl;
      }
      // �������ɱ��޸�
      //DAY = 9;
      cout << DAY << endl;
    return 0;
}
