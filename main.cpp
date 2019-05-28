#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#pragma warning(disable : 4996)
char nozuo[5][10] = { 0 };   //Ïû³ý×óµÝ¹éºó
char quhuo[8][10] = { 0 };    //Ïû³ý¡°|¡±·ûºÅ ·½±ãÌîÈë±í¸ñ
char quhuo2[8][10] = { 0 };
char fzj[10] = { 0 };   //·ÇÖÕ½á
int rb[5][6];   //M[][]·ÖÎö±í
char zjf[20];
int num = 0;
int num1 =0;
char first[5][10] = {0};    //¹¹½¨µÄFIRST¼¯
char follow[5][10] = { 0 };    //¹¹½¨µÄFOLLOW¼¯
char tskz[10];   //¹¹½¨µÄÌØÊâ¿Õ¼¯×é  ·½±ãÔËËã
void jczdg()  //¼ì²â×óµÝ¹é
{
	int i;
	int j = 0;
	
	char *p; 
	char *e;
	int sign;
	
	char yf[3][10] = { "E:E+T|T","T:T*F|F","F:(E)|i" };
	
	
	for (i = 0; i < 3; i++)
	{
		e = yf[i];
		for (int x1 = 0; e[x1] != '\0'; x1++)
		{
			if (e[x1] >= 'A'&&e[x1] <= 'Z')
			{
				if (num >= 1)
				{
					sign = 0;
					for (int q = 0; q < num; q++)
					{
						if (e[x1] != fzj[q])
						{
							sign++;
						}
					}
					if (sign == num)
					{
						fzj[num] = e[x1];
						num++;
					}
				}
				else {
					fzj[num] = e[x1];
					num++;
				}
			}
		}
	}


   srand(time(NULL));
		for (int h = 0; h < 3; h++)
		{
			bool r1 = 1;
			p = yf[h];
			if (p[0] == p[2] && p[3] != '|')   //´æÔÚ×óµÝ¹é
			{
				nozuo[j][0] = p[0];
				nozuo[j][1] = '-';
				nozuo[j][2] = '>';
				nozuo[j][3] = '\0';
				int o;
				do {
					o = rand() % 26;
					o += 'A'; 
					int sign = 0;
					for (int u = 0; u < num; u++)
					{
						if(o!=fzj[u])
						{
							sign++;
						}
						
					}
					if (sign == num)
						{  fzj[num] = o;
				            num++;
							r1 = 0;
						}	
				} while (r1);       // oÎªÐÂÖÕ½á·û
				char *a;
				char s[20];
				a = s;
				int k = 0;
				for (i = 3; p[i] != '|'; i++)
				{
					a[k] = p[i];
					k++;
				}
				a[k] = o;
				
				k++; a[k] = '|';
				k++;
				a[k] = '!';      //aÖÐ´æ·ÅµÄÊÇ¦Á   //$ºÅ´úÌæ Ò»àÛÉ­Åµ
				k++; a[k] = '\0';
				char *b;      //   ´æ·ÅµÄÊÇ¦Â
				char l[20];
				b = l;
				i++; k = 0;
				for (; p[i] != '\0'; i++)
				{
					b[k] = p[i];
					k++;
				}
				b[k] = o;
				k++; b[k] = '\0';//¾®ºÅ´úÌæ Ò»àÛÉ­Åµ
				strcat(nozuo[j], b);    //´ËÎªÏû³ýµÄµÚÒ»¾ä
				j++;       //´Ë´¦ÎªµÚ¶þ¾ä
				nozuo[j][0] = o;
				nozuo[j][1] = '-';
				nozuo[j][2] = '>';
				nozuo[j][3] = '\0';
				strcat(nozuo[j], a);
				j++;
			}
			else {
				char *w;
				w = nozuo[j];
				int m = 0;
				for (m = 0; p[m] != '\0'; m++)
				{
					w[m] = p[m];
				}
				w[m] = '\0';
				j++;
				for (int s = m; s >=2; s--)
				{
					w[s + 1] = w[s];
				}
				w[1] = '-';
				w[2] = '>';
			}
		}
		fzj[num] = '\0';
		num++;
	printf("ÒÔÏÂÎªÏû³ý×óµÝ¹éºóµÄÎÄ·¨:\n");
		for (i = 0; i < 5; i++)
		{
			
			printf("     %s\n", nozuo[i]);
	}
		printf("\n");


}
char * merge1(char *s1,const char *s2)  //s1ÐèÒª°üº¬s2 s2ÔªËØ²åÈës1
{
	int i, j, s, h;
	int sign = 0;  //ÅÐ¶ÏÖØ¸´
	i = strlen(s1);
	j = strlen(s2);
	
	if (i == 0)
	{
		for (s = 0; s < j; s++)
		{
			s1[i] = s2[s];
			i++;
		}
	}
	if (i > 0)
	{
		for (s = 0; s < j; s++)
		{
			sign =0;
			
			for (h = 0; h < i; h++)
			{
				if (s1[h] != s2[s])
				{
					sign++;
				}
				
			}
			if (sign == i)    //²»ÖØ¸´
			{
				s1[i] = s2[s];
				i++;
				s1[i] = '\0';
				
				
			}
			
		}


	}
	
	s1[i] = '\0';

	return(s1);
}
char * merge2(char *s1, const char *s2)  //s1ÐèÒª°üº¬s2 s2ÔªËØ²åÈës1   !!Õë¶ÔÇófollow¼¯¹æÔò2µÄÈÚºÏ
{
	int i, j, s, h;
	int sign = 0;  //ÅÐ¶ÏÖØ¸´
	i = strlen(s1);
	j = strlen(s2);
	//printf("i=%d", i);
	//printf("j=%d", j);
	if (i == 0)
	{
		for (s = 0; s < j; s++)
		{
			if (s2[s] != '!') {
				s1[i] = s2[s];
				i++;
			}
		}
	}
	if (i > 0)
	{
		for (s = 0; s < j; s++)
		{
			sign = 0;

			for (h = 0; h < i; h++)
			{
				if (s1[h] != s2[s])
				{
					sign++;
				}

			}
			if (sign == i&&s2[s]!='!')    //²»ÖØ¸´
			{
				s1[i] = s2[s];
				i++;
				s1[i] = '\0';


			}

		}


	}

	s1[i] = '\0';
	//	puts(s1);
	return(s1);
}
int quedingxh(char a)
{
	int num1=11;    //Èç¹û¶¼²»ÏàµÈ ·µ»Ø11
	for (int i = 0; i < strlen(fzj); i++)
	{
		if (a == fzj[i])
		{
			num1 = i;
			break;
		}
	}
	return num1;
}
int quedingxh2(char a)
{
	int num1=11;   //Èç¹û¶¼²»ÏàµÈ  
	for (int i = 0; i < strlen(zjf); i++)
	{
		if (a == zjf[i])
		{
			num1 = i;
			break;
		}
	}
	return num1;
}
char quedingfuhao(int x)
{
	char a;
	a = zjf[x];
	return a;
}
void qfirst()
{
	printf("ÒÔÏÂÎªËùÇóµÄFIRST¼¯\n");
	int i, j, k, l, x;
	
	
	char *p;
	char *q;


	for (i = 0; i < 5; i++)
	{
		char zj[100];
		zj[0] = '\0';
		q = zj;
		p = nozuo[i];
		if (p[3] < 'A' || p[3] > 'Z')     //¼´µÚÒ»¸ö´ÊÎªÖÕ½á·û
		{
			int r;
			r = quedingxh(p[0]);    //È·¶¨ÕÒµ½µÄÊÇË­µÄfirst¼¯
			//printf("r=%d", r);
			x = strlen(zj);
			q[x] = p[3];
			x++;
			q[x] = '\0';
			for (int u = 0; u < strlen(nozuo[i]); u++)
			{
				if (p[u] == '|' && (p[u + 1]<'A' || p[u + 1]>'Z'))
				{
					x = strlen(zj);
					q[x] = p[u + 1];
					x++;
					q[x] = '\0';
					break;
				}
			}
			char *n;
			n = first[r];
			merge1(n, q);
			printf("FIRST(%c)={%s}\n", p[0], first[r]);


		}

	}
	for (i = 0; i < strlen(fzj); i++)
	{
		p = nozuo[i];
		if (p[3] >= 'A'&&p[3] <= 'Z')
		{
			int w = quedingxh(p[0]);
			int g = quedingxh(p[3]);
			char *u;
			char *t;
			u = first[w];
			t = first[g];
			merge1(u, t);

		}
	}
	for (i = 0; i < strlen(fzj); i++)
	{
		p = nozuo[i];
		if (p[3] >= 'A'&&p[3] <= 'Z')
		{
			int w = quedingxh(p[0]);
			int g = quedingxh(p[3]);
			char *u;
			char *t;
			u = first[w];
			t = first[g];
			merge1(u, t);
			printf("FIRST(%c)={%s}\n", p[0], first[w]);
		}
	}

	printf("\n");
}
void qfollow()
{
	printf("ÒÔÏÂÎªÇóFOLLOW¼¯¹ý³Ì\n");
	
	follow[0][0] = '#';
	follow[0][1] = '\0'; //¸ù¾Ý¹æÔò   ¶ÔÓÚ¿ªÊ¼·ûºÅÌí¼Ó#

	char *q;
	int i, j, k, l;
	printf("¹æÔò2\n");
	for (i = 0; i < 5; i++)
	{
		q = nozuo[i];

		if (q[3]<'A' || q[3]>'Z' && (q[4] > 'A'&&q[4] < 'Z'))   //¹æÔò2
		{
			if (q[5]<'A' || q[5]>'Z'&&q[5] != '\0'&&q[5] != '!')  //¦Â²»µÈÓÚÒ×ÆÕÉ­Åµ
			{
				int m = quedingxh(q[4]);
				char *o;
				char s[10];

				o = s;
				o[0] = q[5];
				o[1] = '\0';
				merge1(follow[m], o);
				printf("FOLLOW(%c)={%s}\n", fzj[m], follow[m]);
			}
			if (q[5] >= 'A'&&q[5] <= 'Z')
			{
				int m = quedingxh(q[5]);
				int n = quedingxh(q[4]);

				merge2(follow[n], first[m]);
				//puts(follow[n]);
				printf("FOLLOW(%c)={%s}\n", fzj[n], follow[n]);
			}
		}

	}  //¹æÔò2
	tskz[0] = '\0';
	for (i = 0; i < 5; i++)   //ÌØÊâ¿Õ¼¯×é
	{
		q = nozuo[i];
		for (int s = 0; q[s] != '\0'; s++)
		{
			if (q[s] == '!')
			{
				
				tskz[num1] = q[0];
				num1++;
			}
		}
	}
	tskz[num1] = '\0';
	puts(tskz);

printf("¹æÔò3\n");
	for (i = 0; i < 5; i++)
	{   
		q = nozuo[i];
		for (k = 3; k < strlen(q); k++)
		{
			if ((q[k]>='A'&&q[k]<='Z'))//ÐÎÊ½ÎªA::=aB¦Â
			{
				bool y1 = false;
				for (int d = 0; d <= strlen(tskz); d++)
				{
					if (q[k + 1] == tskz[d]&&q[k+1]!=q[0])
					{
						y1 = true;
						break;
					}
				}
				if (y1)
				{
					int m = quedingxh(q[0]);    //Ö¸ÏòA
					int n = quedingxh(q[k]);   //Ö¸ÏòB
					char *c;
					char *b;
					b = follow[m];
					c = follow[n];
					merge1(c, b);
					printf("FOLLOW(%c)±»°üÓÚFOLLOW(%c),FOLLOW(%c)={%s} \n", q[0], q[k], q[k], c);

				}
				
		}
			if((q[k]>='A'&&q[k]<='Z')&&q[k+1]=='\0'&&q[k]!=q[0])//ÐÎÊ½ÎªA::=aB
			{
				int m = quedingxh(q[k]);
				int n = quedingxh(q[0]);
				char *d;
				char *f;
				d = follow[m];
				f = follow[n];
				merge1(d, f);
				printf("FOLLOW(%c)±»°üÓÚFOLLOW(%c),FOLLOW(%c)={%s}\n", q[0], q[k], q[k], follow[m]);
		 }
		}
	}

	
}
void xiaohuo()
{

	char *q;
	char *y;
	int num3 = 0;
	for (int i = 0; i < 5; i++)    //È¥³ý»ò·ûºÅ  ·Ö³ÉÁ½¾ä
	{
		y = nozuo[i];
		for (int s = 0; s < strlen(y); s++)
		{
			if (y[s] == '|')
			{
				char t1[10];
				
				t1[0] = y[0];
				t1[1] = '-';
				t1[2] = '>';
				t1[3] = '\0';
				int h, o;
				for ( h = 3; y[h] != '|'; h++)
				{
					t1[h] = y[h];
				}
				t1[h] = '\0';
			
				q = quhuo[num3];
				merge1(q, t1);
				
				num3++;
				char t2[10];
				t2[0] = y[0];
				t2[1] = '-';
				t2[2] = '>';
				t2[3] = '\0';
				h++;
				for (o=3; y[h] != '\0'; h++,o++)
				{
					t2[o] = y[h];
				}
				t2[o] = '\0';
			
				q = quhuo[num3];
				merge1(q, t2);
				
				num3++;
				
				 }
		}
		
	}    
	for (int i = 0; i < 5; i++)
	{
		y = nozuo[i];
		bool x = true;
		for (int s = 0; s < strlen(y); s++)
		{
			if (y[s] == '|')
			{
				x = false;
		   }
		}
		if (x)
		{
			merge1(quhuo[num3], y);
		
			num3++;
			
		}

	}
	
	for (int i = 0; i < 8; i++)  //·½±ã×Ü¿Ø³ÌÐòÊ¹ÓÃµÄÊý×équhuo2
	{
		char *u = quhuo[i];
		char s[20];
		char *q;
		q = s;
		int d = 0;
		int h = 3;
		do {
			s[d] = u[h];
			d++;
			h++;
		} while (u[h] != '\0');
		s[d] = '\0';
		merge1(quhuo2[i], q);
		
	}  
	printf("\n");
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
void fenxibiao()
{
	

	char *y;
	char temp[10];
	printf("          ");
	for (int i = 0; i < 5; i++)
	{
		merge2(zjf, follow[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		merge2(zjf, first[i]);   //µÃµ½ËùÓÐÖÕ½á·ûºÅ  °üÀ¨#
	}

	
}
void FXB()
{    char *q;

for (int i = 0; i < 5; i++)
{
	for (int j = 0; j < 6; j++)
	{
		rb[i][j] = 8;
	}
}
	for (int a = 0; a < 8; a++)
	{
		q = quhuo[a];
	
		if (q[3] == '!')  // X->¿Õ¼¯ Çé¿ö
		{
			int m = quedingxh(q[0]);  //¾ä×Ó¿ªÍ··ûºÅËù´ú±íµÄÐòºÅ  ·ÖÎö±íµÄÐÐÊý¡£
			char *p;
			p = follow[m];     
			for (int b = 0; b < 6; b++)
			{
				bool t1 = false;
				for (int c = 0; c < strlen(p); c++)    //pÖ¸Ïò¾äÍ··ûºÅµÄfollow¼¯
				{
					if (p[c] == zjf[b]||(p[c]=='!'&&zjf[b]=='#')&&(rb[m][b]==8||rb[m][b]==9))
					{
						rb[m][b] = a;
						t1 = true;
					}
				}
				if (!t1)
				{
					if (rb[m][b] == 9 || rb[m][b] == 8)
					{
						rb[m][b] = 9;
					}
				}
			   
			}
	  
	}
		if (((q[3]<'A' || q[3]>'Z') && q[3] != '!')||q[3]=='('||q[3]=='+')   //²»ÊÇ¿Õ¼¯Ò²²»ÊÇÖÕ½á·û  ·ÇÖÕ½á·û
		{
			int m = quedingxh(q[0]);  //¾ä×Ó¿ªÍ··ûºÅËù´ú±íµÄÐòºÅ  ·ÖÎö±íµÄÐÐÊý¡£
			char *p;
			for (int b = 0; b <6; b++)
			{
				if (zjf[b] == q[3] && (rb[m][b] == 8 || rb[m][b] == 9))
				{
					rb[m][b] = a;
				}
				else {
					if (rb[m][b] == 9 || rb[m][b] == 8)
					{
						rb[m][b] = 9;
					}
				}
			}
		}
		{
			if (q[3] >= 'A'&&q[3] <= 'Z')
			{
				int m = quedingxh(q[0]);//¾ä×Ó¿ªÍ··ûºÅËù´ú±íµÄÐòºÅ  ·ÖÎö±íµÄÐÐÊý¡£
				int n = quedingxh(q[3]);
				char *p;
				p = first[n];
				{
					for (int b = 0; b <6; b++)
					{
						bool e = false;
						for (int c = 0; c < strlen(p); c++)
						{
							if(zjf[b]==p[c])
							{
								e = true;
								rb[m][b] = a;
							}
						}
						if (e)
						{

						}
						else {
							if (rb[m][b] == 9 || rb[m][b] == 8)
							{
								rb[m][b] = 9;
							}
						}
					}
				}
			}
		}
	}
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 6; j++)
	//	{
	//		printf("%d     ", rb[i][j]);
	//	}
	//	printf("\n");
	//}
}
void dyrb()
{
	printf("\n");
	printf("       ");
	for (int i = 0; i < strlen(zjf); i++)
	{
		printf("%c        ", zjf[i]);
	}
	printf("\n");
	for (int i = 0; i < strlen(fzj); i++)
	{
		printf("%c      ", fzj[i]);
		for (int a = 0; a < strlen(zjf); a++)
		{
			if (rb[i][a] == 9)
			{
				printf("ERROR   ");
			}
			if (rb[i][a] < 9)
			{
				printf("%s    ", quhuo[rb[i][a]]);
			}
		}
		printf("\n");
	}

}
void zkcx()
{
	char *s;    //s´¢´æ´øÅÐ¶ÏµÄ¾ä×Ó×Ö·û´®
	char a[99];
	s = a;
	printf("\n\n\nÇëÊäÈëËù·ÖÎöµÄ¾ä×Ó:");
    gets_s(s,98);
	int i;
	for ( i=0; i < strlen(s); i++)
	{
		if (s[i] != '('&&s[i] != ')'&&s[i] != '+'&&s[i] != '*')
		{
			s[i] = 'i';
		}
	}
	s[i] = '#';
	s[i + 1] = '\0';     
	
	puts(s);
	printf("\n");
	printf("\t");
	printf("²½Öè\t·ÖÎöÕ»\t\tÓàÁôÊäÈë´®\tËùÓÃ²úÉúÊ½");
	printf("\n");
	char zhan[99];
	char *z;
	z = zhan;
	zhan[0] = '#';
	zhan[1] = 'E';
	zhan[2] = '\0';
	bool the = true;
	int bzs = 1;
	while (zhan[1] != '\0')   //Ö»Òª·ÖÎöÕ»²»Ö»Ê£ÏÂ#  ¾Í¼ÌÐø×ö
	{   
      int x1 = strlen(zhan);
	  char b;
	  b = zhan[x1 - 1];      //bÎª·ÖÎöÕ»×îºó×Ö·û
	  int m = quedingxh(b);
	  char c;               //cÎªÊäÈë´®×îÇ°×Ö·û
	  c = s[0];
	  int n = quedingxh2(c);
	  if(m!=11)
	  { 
	  if (rb[m][n] == 9)
	  {
		  printf("\t%d\t%-9s\t%-9s\tERROR", bzs, z, s);printf("\n"); the = false;
		  
		  break;
		  
	  }
	  if (rb[m][n] < 9)
	  {
		  printf("\t%d\t%-9s\t%-9s\t%-9s", bzs, z, s,quhuo[rb[m][n]]);
		  printf("\n");
		  char *t;
		  t = quhuo2[rb[m][n]];
		  if ((t[0] >= 'A'&&t[0] <= 'Z')|| (t[1] >= 'A'&&t[1] <= 'Z'&&t[1]!='E'))
		  {
			  for (int j = strlen(t)-1; j>=0; j--)
			  {
				  z[x1 - 1] = t[j];
				  x1++;
			  }
			  z[x1 - 1] = '\0';
		  }
		  if (t[0] == '(')
		  {

			  for (int j = strlen(t) - 1; j >= 0; j--)
			  {
				  z[x1 - 1] = t[j];
				  x1++;
			  }
			  z[x1 - 1] = '\0';
		  }
		  if (t[0] == 'i')
		  {
			  z[x1 - 1] = 'i';
		  }
		  if (t[0] == '!')
		  {
			  z[x1 - 1] = '\0';
		  }
		 
	  }
	  }
	  if (m == 11)
	  {
		  if (b != c)
		  {
			  printf("\t%d\t%-9s\t%-9s\tERROR", bzs, z, s); printf("\n"); the = false;
			  break;
			  
			  
		  }
		  if (b == c)
		  {
			  printf("\t%d\t%-9s\t%-9s\t\t", bzs, z, s);
			  printf("\n");
			  z[x1 - 1] = '\0';
			  int h;
			  for (h = 1; h < strlen(s); h++)
			  {
				  s[h - 1] = s[h];
			  }
			  s[h - 1] = '\0';
		  }
	  }
	  bzs++;
	}
	if (s[0] == z[0] && s[1] == '\0'&&the ==true)
	{
		char s[10] = { '#' };
		char a[10] = { '#' };
		printf("\t%d\t%-9s\t%-9s\t³É¹¦",bzs,s,a);
		printf("\n");
	}
}
int main()
{
	jczdg();
	//puts(fzj);
	qfirst();
	qfollow();
	xiaohuo();
	fenxibiao();
	FXB();
	dyrb();
	zkcx();
	/*printf("·ÇÖÕ½á·û¼¯ºÏ£º");
	for (int i = 0; i < 5; i++)
	{
		printf("%c", fzj[i]);
	}
	printf("\nÖÕ½á·û¼¯ºÏ£º");
	for (int i = 0; i <strlen(zjf); i++)
	{
		printf("%c", zjf[i]);
	}
	printf("\n");
	for(int i = 0; i < 8; i++)
	{
		printf("%d. %s\n", i, quhuo[i]);

	}
	for (int i = 0; i < strlen(fzj); i++)
	{
		
		for (int j = 0; j < strlen(zjf); j++)
		{
			printf("%d ", rb[i][j]);
		}
		printf("\n");
	}*/
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("FIRST(%c)={%s}\n", fzj[i], first[quedingxh(fzj[i])]);
	//	printf("FOLLOW(%c)={%s}\n", fzj[i], follow[quedingxh(fzj[i])]);
	//}
	system("pause");
}
