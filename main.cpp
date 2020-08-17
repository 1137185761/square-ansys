//项目描述
/*
1.获取能量数据(读取数据文件)
2.核心算法:短时间窗口的能量值平方和的平均值/长时间窗口的能量值平方和的平均值
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

	cout << "请输入文件名";
	cin >> filename;

	ifstream file;
	file.open(filename.c_str());
	
	if (file.fail())
	{
		cerr << "文件打开失败" << endl;
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
				cout << "可能的事件发生在" << time * (i + 1) <<"s"<< endl;
			}
				
		}
		delete[] sensor;//释放内存,防止内存泄漏
	}
	file.close();
	return 0;
}
double power_ansys(double squ[], int len, int n)
{
	double avg = 0;
	for (int i = 0; i < n; i++)
	{
		avg += pow(squ[len - i], 2);//pow(),前一个参数是数值,后一个是几次方;
	}

	return avg / n;
}