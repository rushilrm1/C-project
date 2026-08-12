#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class String
{
	char *p;
	public:
	String()
	{
		p=0;
	}
	String(const char *s)
	{
		p=new char[strlen(s)+1];
		strcpy(p,s);
	}
	String(const String &s)
	{
		p=new char[strlen(s.p)+1];
		strcpy(p,s.p);
	}
	~String()
	{
		if(p!=0)
			delete []p;
	}
	String operator = (String &t)
	{
		p=new char[strlen(t.p)+1];
		strcpy(p,t.p);
		return *this;
	}
	String operator + (String &t)
	{
		String s;
		s.p=new char[(strlen(p)+strlen(t.p)+1)];
		strcpy(s.p,p);
		strcat(s.p,t.p);
		return s;
	}
	char & operator [] (int i)
	{
		return p[i];
	}
	bool operator > (String &t)
	{
		if(strcmp(p,t.p) > 0)
			return true;
		else
			return false;
	}
	bool operator < (String &t)
	{
		if(strcmp(p,t.p) < 0)
			return true;
		else 
			return false;
	}
	bool operator >= (String &t)
	{
		if(strcmp(p,t.p)>=0)
			return true;
		else 
			return false;
	}
	bool operator <= (String &t)
	{
		if(strcmp(p,t.p) <= 0)
			return true;
		else
			return false;
	}
	bool operator != (String &t)
	{
		if(strcmp(p,t.p) != 0)
			return true;
		else 
			return false;
	}
	bool operator == (String &t)
	{
		if(strcmp(p,t.p) == 0)
			return true;
		else 
			return false;
	}
//-----------------------friend func's------------------------------//

	friend ostream& operator << (ostream &out,const String &s);
	friend istream& operator >> (istream &in,String &s);
	friend void strcpyy(String &,String &);
	friend void strncpyy(String &,String &,int);
	friend int strcmpp(String &,String &); 
	friend int strncmpp(String &,String &,int); 
	friend void strncatt(String &,String &,int);
	friend void strcatt(String &,String &);
	friend void strrevv(String &);
	friend void strupper(String &);
	friend void strlower(String &);
	friend int strchrr(String &,char);
	friend int strrchrr(String &,char);
	friend char * strstrr(String &,const char *);
	friend int strlenn(String &); 
};

int strlenn(String &s)
{
	int i=0;
	for(i=0;s.p[i];i++);
	return i;
}

char * strstrr(String &m,const char *s)
{
	int i=0,j=0,k=0;
	for(i=0;m.p[i];i++)
	{
		if(s[0]==m.p[i])
		{
			for(k=i+1,j=1;s[j];j++,k++)
				if(s[j]!=m.p[k])
					break;
			if(s[j]=='\0')
				return (char *)&m.p[i];
		}
	}
	return 0;
}

int strrchrr(String &s,char c)
{
	int i=0,l=strlen(s.p);
	for(i=l-1;i>=0;i--)
		if(s.p[i]==c)
			return i;
	if(s.p[i]=='\0')
		return 0;
}

int strchrr(String &s,char c)
{
	int i=0;
	for(i=0;s.p[i];i++)
		if(s.p[i]==c)
			return i;
	if(s.p[i]=='\0')
		return 0;
}

void strupper(String &u)
{
	for(int i=0;u.p[i];i++)
		if(u.p[i]>='a'&&u.p[i]<='z')
			u.p[i]^=32;
}

void strlower(String &u)
{
	for(int i=0;u.p[i];i++)
		if(u.p[i]>='A'&&u.p[i]<='Z')
			u.p[i]^=32;
}

void strrevv(String &r)
{
	int l=strlen(r.p);
	char t;
	for(int i=0,j=l-1;i<j;i++,j--)
	{
		t=r.p[i];
		r.p[i]=r.p[j];
		r.p[j]=t;
	}
}

void strncatt(String &d,String &s,int n)
{
	char *t;
	t=new char[strlen(d.p)+n+1];
	int i=0,j=0;
	while(d.p[i])
	{
		t[i]=d.p[i];
		i++;
	}
	while(j<n)
		t[i++]=s.p[j++];
	t[i]='\0';
	delete []d.p;
	d.p=t;
}

void strcatt(String &d,String &s)
{
	char *t;
	t=new char[strlen(d.p)+strlen(s.p)+1];
	int i=0,j=0;
	while(d.p[i])
	{
		t[i]=d.p[i];
		i++;
	}
	while(s.p[j])
		t[i++]=s.p[j++];
	t[i]='\0';
	delete []d.p;
	d.p=t;
}

int strncmpp(String &d,String &s,int n)
{
	int i=0;
	for(i=0;i<n;i++)
		if(d.p[i]!=s.p[i])
			return d.p[i]-s.p[i];
	if(i==n)
		return 0;
}

int strcmpp(String &d,String &s)
{
	int i=0;
	for(i=0;d.p[i]&&s.p[i];i++)
		if(d.p[i]!=s.p[i])
			return d.p[i]-s.p[i];
	if(d.p[i]=='\0'&&s.p[i]=='\0')
		return 0;
	if(d.p[i]=='\0'&&s.p[i]!='\0')
		return -s.p[i];
	if(s.p[i]=='\0'&&d.p[i]!='\0')
		return d.p[i];
}


void strcpyy(String &s1,String &s2)
{
	int i;
	if(s1.p!=0)
		delete []s1.p;
	s1.p=new char[strlen(s2.p)+1];
	for(i=0;s2.p[i];i++)
		s1.p[i]=s2.p[i];
	s1.p[i]='\0';
}

void strncpyy(String &s1,String &s2,int n)
{
	int i;
	if(s1.p!=0)
		delete []s1.p;
	s1.p=new char[n+1];
	for(i=0;i<n;i++)
		s1.p[i]=s2.p[i];
	s1.p[i]='\0';
}

ostream& operator << (ostream &out,const String &s)
{
	out<<s.p;
	return out;
}

istream& operator >> (istream &in,String &s)
{
	fstream fp("data",ios::in|ios::out|ios::trunc);
	char ch;
	int l=0;
	while(1)
	{
		in.get(ch);
		l++;
		fp.write(&ch,sizeof(ch));		
		if(ch==10||ch=='\n'||ch=='\r')
			break;
	}
	s.p=new char [l];
	int i=0;
	while(i<l)
		fp.read(&s.p[i++],sizeof(ch));
	s.p[i-1]='\0';
	fp.close();
	remove("data");
	return in;
}

int main()
{
	String s("bye");
	String s1("hello");
	cout<<"s1="<<s1<<endl;
	String s2(s1);
	cout<<"s2="<<s2<<endl;
	String s3=s1=s;
	cout<<"s3="<<s3<<endl;
	String s4=s2+s3;
	cout<<"s4="<<s4<<endl;
	cout<<(s3>s2)<<endl;
	cout<<(s2<s4)<<endl;
	String s5;
	cout<<"enter s5\n";
	cin>>s5;
	cout<<s5<<endl;
	String s6("ai"),s7("bye"),s8("ai");
	cout<<(s6>=s7)<<endl;
	cout<<(s6!=s7)<<endl;
	cout<<(s6==s8)<<endl;
	String p1="hailk";
	for(int i=0;p1[i];i++)
		cout<<p1[i]<<' ';
	cout<<endl;
}




