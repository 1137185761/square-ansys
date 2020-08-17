//��Ŀ����
/*
1.��ȡ��������(��ȡ�����ļ�)
2.�����㷨:��ʱ�䴰�ڵ�����ֵƽ���͵�ƽ��ֵ/��ʱ�䴰�ڵ�����ֵƽ���͵�ƽ��ֵ
*/
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>

using namespace std;
double power_ansys(double squ[],int len, int n);

int main()
{
	string filename;
	double* sensor=NULL;
	int num=0;
	double time=0;
	double short_power, long_power;
	int short_win_num=2, long_win_num=5;
	double result = 0;
	double limit = 1.5;

	cout << "�������ļ���";
	cin >> filename;

	ifstream file;
	file.open(filename.c_str());
	
	if (file.fail())
	{
		cerr << "�ļ���ʧ��" << endl;
		exit(-1);
	}
	else
	{
		file >> num >> time;
		cout << "num= " << num << " time =" << time << endl;
		sensor = new double[num];
		for (int i = 0; i < num; i++)
		{
			file >> sensor[i];
		}
		for (int i = 4; i < num; i++)
		{
			short_power = power_ansys(sensor, i, short_win_num);
			long_power = power_ansys(sensor, i, long_win_num);
			result = short_power / long_power;
			if (result > limit)
			{
				cout << "���ܵ��¼�������" << time * (i + 1) <<"s"<< endl;
			}
				
		}
		delete[] sensor;//�ͷ��ڴ�,��ֹ�ڴ�й©
	}
	file.close();
	return 0;
}
double power_ansys(double squ[], int len, int n)
{
	double avg = 0;
	for (int i = 0; i < n; i++)
	{
		avg += pow(squ[len - i], 2);//pow(),ǰһ����������ֵ,��һ���Ǽ��η�;
	}

	return avg / n;
}