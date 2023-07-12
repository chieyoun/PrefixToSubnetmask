#include <stdio.h>

int twoConvertTen(int num);

int main(){

	

	int x; 

	int a,b,c,d;

	int binary=1;

	int i = 0;

	int ten;

	a=0;

	b=0;

	c=0;

	d=0;

	

	scanf("%d", &x);

	

	if(x>=8){ 

		a = 255;

		if(x>=16){
			b=255;

			if(x>=24){//x�� 24�Ͻ� 11111111.11111111.11111111.0 �̹Ƿ� 255.255.255.0, 16<x<24�̶�� else������ ��.

				c=255;

				if(x>=32){//x�� 32�Ͻ� 11111111.11111111.11111111.11111111 �̹Ƿ� 255.255.255.255, 24<x<32�̶�� else������ ��.

					d=255;

				}

				else if(x != 24){

					x = x-24;

					for(i=1;i<x;i++){

						binary = binary*10+1;

					}

					for(i=0;i<8-x;i++){

						binary = binary *10;

					}

					ten = twoConvertTen(binary);

					d = ten;

					binary = 1;

				}			

			}

			else if(x != 16){

				x = x-16;

				for(i=1;i<x;i++){

					binary = binary*10+1;

				}

				for(i=0;i<8-x;i++){

					binary = binary *10;

				}

				ten = twoConvertTen(binary);

				c = ten;

				binary = 1;

			}

			

		}

		else if(x != 8){

			x = x-8;

			for(i=1;i<x;i++){

				binary = binary*10+1;

			}

			for(i=0;i<8-x;i++){

				binary = binary *10;

			}

			ten = twoConvertTen(binary);

			b = ten;

			binary = 1;

			}

	}

	else{// ���̳ʸ� -> ������ 

		for(i=1;i<x;i++){

			binary = binary*10+1; // �� ����� ���ָ� ���� x�� 7�̸� 1111111�� ��. 

		}

		for(i=0;i<8-x;i++){

			binary = binary *10; // �� ����� ���ָ�  ���� x�� 7�̸� 11111110�� ��. 

		}

		ten = twoConvertTen(binary); // ������ ��ȯ �Լ� ȣ��. 

		a = ten;

		binary = 1;	//���� �� �ʱ�ȭ 

	}

	

	printf("%d.%d.%d.%d", a, b,c,d);//���� �� �� 

	return 0;

} 


int twoConvertTen(int num){//2���� -> 10���� ��ȯ �Լ�. 

	

	int result = 0;

	int mul = 1;

	while(num>0){

		if(num%2){

			result += mul;

		}

		mul *= 2;

		num /=10;

	}

	return result;

}



