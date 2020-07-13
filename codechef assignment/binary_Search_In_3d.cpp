#include<bits/stdc++.h>
using namespace std;
class binary_Search_In_3d{
private:
	int x,y,z,num;
	int ***arr;
	int i,j,k;
	int midx , midy,midz;
public:
	binary_Search_In_3d();
	int binarySearchInFirstDim(int ,int ,int ,int ,int ,int);
	int binarySearchInSecondDim(int ,int ,int ,int ,int);
	int binarySearchInThirdDim(int ,int ,int ,int);
	void find();
	void display();
	~binary_Search_In_3d();
	static int count;
};
int binary_Search_In_3d :: count = 0;
binary_Search_In_3d :: binary_Search_In_3d(){
	cin>>x>>y>>z>>num;
	arr = new int **[x];
	for(i = 0 ; i < x ; i++){
		arr[i] = new int *[y];
		for(j = 0; j < y ;j++){
			arr[i][j] = new int [z];
		}
	}

	for(i = 0 ; i < x ; i++){
		for(j = 0 ; j < y ;j++){
			for(k = 0 ; k < z ; k++){
				cin >> arr[i][j][k];
			}
		}
	}
}
int binary_Search_In_3d :: binarySearchInThirdDim(int xValue , int yValue , int l ,int h){
	while(l<=h){
		midz = (l + h)/2;
		// cout<<"***"<<endl;
		count++;
		if(arr[xValue][yValue][midz] == num){
			cout << xValue <<" "<< yValue <<" "<<midz <<" " << endl;
			return 1;
		}else if (num < arr[xValue][midy][midz]){
			h = midz-1;
		}else{
			l = midz+1;
		}
	}
	return 0;
}
int  binary_Search_In_3d :: binarySearchInSecondDim(int xValue , int l ,int h , int zi , int zf){
	
	while(l<=h){
		midy = (l + h)/2;
		// cout<<"**"<<endl;
		count++;
		if(arr[xValue][midy][zi] <= num && num <= arr[xValue][midy][zf]){
			cout << arr[xValue][midy][zi] << " "<< arr[xValue][midy][zf]<<endl;
			if(binarySearchInThirdDim(midx ,midy,0,z-1) == 1){
				return 1;
			}else{
				return 0;
			}
		}else if (num < arr[xValue][midy][zi]){
			h = midy-1;
		}else{
			l = midy+1;
		}
	}
	return 0;
}
int binary_Search_In_3d :: binarySearchInFirstDim(int l , int h , int yi , int zi ,int yf , int zf){
	while(l<=h){
		midx = (l + h)/2;
		// cout<<"*"<<endl;
		count++;
		if(arr[midx][yi][zi] <= num && num <= arr[midx][yf][zf]){
			cout << arr[midx][yi][zi] << " "<<arr[midx][yf][zf]<<endl;
			if(binarySearchInSecondDim(midx , 0 , y-1 , 0 ,z-1) == 1){
				return 1;
			}else{
				return 0;
			}
		}else if (num < arr[midx][yi][zi]){
			h = midx-1;
		}else{
			l = midx+1;
		}
	}
	return 0;
}
void binary_Search_In_3d :: find(){
	int res;
	res = binarySearchInFirstDim(0 , x-1 , 0 , 0 ,y-1 ,z-1);
	if(res == 0){
		cout<<"0"<<endl;
	}
}

void binary_Search_In_3d :: display(){
	for(i = 0 ; i < x ; i++){
		for(j = 0 ; j < y ;j++){
			for(k = 0 ; k < z ; k++){
				cout << arr[i][j][k] << " ";
			}
		}
	}
}
binary_Search_In_3d :: ~binary_Search_In_3d(){
	for( i = 0 ; i < x ; i++){
		for(j =0 ; j< y ; j++){
			delete [] arr[i][j];
		}
		delete [] arr[i];
	}

	delete [] arr;
}
int main(){
	// 3 2 2 28
//2 11 12 19 21 22 28 37 39 69 75 92
	binary_Search_In_3d obj;
	// obj.display();
	obj.find();
	cout<<obj.count;
}