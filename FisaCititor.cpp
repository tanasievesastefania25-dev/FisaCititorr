#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class FisaCititor
{
private:
static int numarFisier;
const int idFisa;
string numeCititor;
double* zileImprumut;
int numarCarti;
public:
//constructor fara parametrii

FisaCititor():idFisa(numarFisier++)
{
	this->numeCititor="NA";
	this->zileImprumut=NULL;
	this->numarCarti=0;
}
//constructorul cu param -validari
FisaCititor(string numeCititorInit,double* zileImprumutInit,int numarCartiInit ) :idFisa(numarFisier++)
{
	if (numeCititorInit.length() > 0)
	{
		this->numeCititor=numeCititorInit;
		
}
	else {
		this->numeCititor="NA";
	}
	if (numarCartiInit > 0 && zileImprumutInit != nullptr)
	{
		this->numarCarti = numarCartiInit;
		this->zileImprumut=new double[numarCartiInit];
		for (int i = 0;i < numarCartiInit;i++)
		{
			this->zileImprumut[i]=zileImprumutInit[i];
		}

	}
	else {
		this->zileImprumut = NULL;
		this->numarCarti = 0;

	}
	
}
//destructor
~FisaCititor() {
	if (zileImprumut != nullptr)
	{
		delete[]this->zileImprumut;
	}
}
//constructor de copiere 
FisaCititor(const FisaCititor& f) :idFisa(numarFisier++)
{
this->numeCititor=f.numeCititor;
if (f.numarCarti > 0 && f.zileImprumut != nullptr)
{
	this->numarCarti = f.numarCarti;
	this->zileImprumut = new double[f.numarCarti];
	for (int i = 0;i < f.numarCarti;i++)
	{
		this->zileImprumut[i] = f.zileImprumut[i];
	}

}
else {
	this->zileImprumut = NULL;
	this->numarCarti = 0;

}


}
//get si set

//numeCititor
string getNumeCititor()
{
	return numeCititor;
}
void setNumeCititor(string numeCititorNou)
{
	if (numeCititorNou.length() > 0)
	{
		this->numeCititor=numeCititorNou;
}
	
}
//zileImprumut;
double* getZileImprumut()
{
	if (zileImprumut != nullptr && numarCarti > 0)
	{
		double* copie=new double[numarCarti];
		for (int i = 0;i < numarCarti;i++)
		{
			copie[i]=zileImprumut[i];
		}
		return copie;
	}
	return nullptr;
}

void setZileImprumut(double* zileImprumutNoi, int numarCartiNoi)
{

	if (numarCartiNoi > 0 && zileImprumutNoi != nullptr)
	{
	delete[]this->zileImprumut;
		this->numarCarti = numarCartiNoi;
		this->numarCarti = numarCartiNoi;
		this->zileImprumut = new double[numarCartiNoi];
		for (int i = 0;i < numarCartiNoi;i++)
		{
			this->zileImprumut[i] = zileImprumutNoi[i];
		}

	}
	

}
//op=
FisaCititor& operator=(const FisaCititor& f)
{
	if (this == &f)
	{
		return *this;
}
	if (zileImprumut != nullptr)
	{
		delete[]this->zileImprumut;
	}

	this->numeCititor = f.numeCititor;
	if (f.numarCarti > 0 && f.zileImprumut != nullptr)
	{
		this->numarCarti = f.numarCarti;
		this->zileImprumut = new double[f.numarCarti];
		for (int i = 0;i < f.numarCarti;i++)
		{
			this->zileImprumut[i] = f.zileImprumut[i];
		}

	}
	else {
		this->zileImprumut = NULL;
		this->numarCarti = 0;
		}
		return *this;
}
//op <<
friend ostream& operator<<(ostream& out, const FisaCititor& f)
{
	out<<f.numeCititor<<endl;
	out<<f.numarFisier<<endl;
	out<<f.idFisa<<endl;
	if(f.zileImprumut !=nullptr && f.numarCarti>0){
	out<<f.numarCarti<<endl;
	for (int i = 0;i < f.numarCarti;i++) {
		out << f.zileImprumut[i];

	}
	
	}
	out << endl;
	return out;
	
	
}
// op >>
friend istream& operator>>(istream& in, FisaCititor& f)
{
	cout<<"Nume Cititor:";
	string nume;
	getline(in,nume);
	if(nume.length()>0)
	f.numeCititor=nume;

	cout<<"numar carti:";
	int nr;
	in>>nr;
	if (nr > 0)
	{
		delete[]f.zileImprumut;
		f.numarCarti=nr;
		f.zileImprumut=new double[nr];
		for (int i = 0;i < nr;i++) {
			cout<<"zile carte"<<i+1<<":";
			in>>f.zileImprumut[i];
		}
		return in;

	}
}
//op >
bool operator>(const FisaCititor& f)const
{
	if (this->numarCarti >f.numarCarti)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//++ preincrementare  care adauga o carte cu 0 zile la finalul vec
FisaCititor& operator++()
{

double* nou=new double[this->numarCarti+1];
for(int i=0;i<this->numarCarti;i++)
nou[i]=this->zileImprumut[i];
nou[this->numarCarti]=0;
delete[]this->zileImprumut;
this->zileImprumut=nou;


this->numarCarti++;
return *this;

}
//posincrementare
FisaCititor& operator++(int) {
	FisaCititor copie=*this;
	this->numarCarti++;
	return copie;
}

//ob+val

FisaCititor operator+(double zile)const
{
FisaCititor copie=*this;
++copie;
copie.zileImprumut[copie.numarCarti-1]=zile;
return copie;

}
//op ==  returneaza true daca 2 fise au acelasi nume de cititor
bool operator==(const FisaCititor& f)const
{
	if (this->numeCititor == f.numeCititor) {
		return true;
  }
	else{
		return false;
  }

}
//op[] zile de la un index cu val de eroare 
double operator[](int index)const
{
	if (this->zileImprumut != nullptr && index >= 0 && index < this->numarCarti)
	{
		return this->zileImprumut[index];
		return -1;
	}
}

//cast la double media zilelor 

//explicit operator double()const
//{
//	if(this->numarCarti==0 || this->zileImprumut==nullptr)
//	return 0;
//	double suma=0;
//	for(int i=0;i<this->numarCarti;i++)
//	suma += this->zileImpumut[i];
//	return suma/this->numarCarti;
//	
//}



////op () nr de zile maxim din vector 
//double operator()() const{
//return this->

//mai trebuie >> == cast + [] 




};
int FisaCititor::numarFisier=0;
int main()
{
	//constr fara param
	FisaCititor f1;
	cout<<f1<<endl;
	//constr cu para,
	double d[] = {34,22,12};
	FisaCititor f2("mihai",d,2);
	cout<<f2<<endl;

	//constr de copiere 
	FisaCititor f4=f2;
	cout<<f4<<endl;

	//op=
	f2=f1;
	cout<<f1<<endl;

	//>
	FisaCititor f5("ion", d, 1);
	cout<<(f5>f2)<<endl;
	//get si set
	cout<<f1.getNumeCititor()<<endl;
	f1.setNumeCititor("andrei");
	cout<<f1.getZileImprumut()<<endl;
	f1.setZileImprumut(d,2);

	//op >>
	FisaCititor f8;
	cin>>f8;
	cout<<f8<<endl;
	//op ==
	cout<<(f4==f2)<<endl;

	//op+ 
	FisaCititor f6=f4+12;
	cout<<f6<<endl;
	cout<<f4<<endl;
	//op[]
	cout<<f4[0]<<endl;
	cout<<f4[10]<<endl;



}