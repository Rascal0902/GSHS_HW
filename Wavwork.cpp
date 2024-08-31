#include <stdio.h>
#include <math.h>
#define MAX 1000
#define PI 3.1415926535
int duration,Fourier,a[1000000],n;
int pcm[44100000][4];
float frequency;
double phase;
typedef unsigned char byte;
void goHz(int low,int high,int Hz)
{
    double freqrps=Hz*2*PI/44100;
    for(int i=low;  i<high; i++)
    {
        for(int j=0; j<4; j++)
        {
           pcm[i][j]=round(MAX*sin(phase));
        }
        phase+=freqrps;
    }

}
void goFourier(int fre,int Fourier)
{
    float sum=0;
    float m;
    for(int i=0;i<n;i++)
    {
        m=(float)(i*PI/n);
        sum=0;
        for(int j=1;j<Fourier*10;j++)
        {
           sum+=400*((float)(4*sin((double)((2*j-1)*m))/((2*j-1)*PI)));
        }
        //printf("%f\n",sum);
        a[i]=sum;
    }
}
void scan()
{
  printf("frequency(hz) : ");
  scanf("%f", &frequency);
  printf("duration(msec) : ");
  scanf("%d", &duration);
  printf("Fourier Transform time : ");
  scanf("%d",&Fourier);
}
struct WAV
{
  byte ChunkID[4];      //"RIFF"
  byte ChunkSize[4];    //*
  byte Format[4];       //"WAVE"
  byte Subchunk1ID[4];  //"fmt "
  byte Subchunk1Size[4];//*
  byte AudioFormat[2];  //*, 1:pcm(pulse code modulation)
  byte NumChannels[2];  //*
  byte SampleRate[4];   //*
  byte ByteRate[4];     //*
  byte BlockAlign[2];   //*
  byte BitsPerSample[2];//*
  byte Subchunk2ID[4];  //"data"
  byte Subchunk2Size[4];//*
};
struct WAVt
{
  byte ChunkID[4];    //"RIFF"
  int ChunkSize;      //*
  byte Format[4];     //"WAVE"
  byte Subchunk1ID[4];//"fmt "
  int Subchunk1Size;  //*
  short AudioFormat;  //*, 1:pcm(pulse code modulation)
  short NumChannels;  //*
  int SampleRate;     //*
  int ByteRate;       //*
  short BlockAlign;   //*
  short BitsPerSample;//*
  byte Subchunk2ID[4];//"data"
  int Subchunk2Size;  //*
};
int ler(byte x[], int n)
{
  int t=0, s=4-n;
  for(int i=0; i<n; i++)
    t |= (x[i]<<((i+s)*8));
  return t>>(s*8);
}
WAVt readheader(WAV x)
{
  WAVt t;
  for(int i=0; i<4; i++) t.ChunkID[i]=x.ChunkID[i];
  t.ChunkSize=ler(x.ChunkSize, 4);
  for(int i=0; i<4; i++) t.Format[i]=x.Format[i];
  for(int i=0; i<4; i++) t.Subchunk1ID[i]=x.Subchunk1ID[i];
  t.Subchunk1Size=ler(x.Subchunk1Size, 4);
  t.AudioFormat=ler(x.AudioFormat, 2);
  t.NumChannels=ler(x.NumChannels, 2);
  t.SampleRate=ler(x.SampleRate, 4);
  t.ByteRate=ler(x.ByteRate, 4);
  t.BlockAlign=ler(x.BlockAlign, 2);
  t.BitsPerSample=ler(x.BitsPerSample, 2);
  for(int i=0; i<4; i++) t.Subchunk2ID[i]=x.Subchunk2ID[i];
  t.Subchunk2Size=ler(x.Subchunk2Size, 4);
  return t;
}
void lew(byte *x, int t, int n)
{
  for(int i=0; i<n; i++, t>>=8)
    x[i] = t&0xFF;
}
WAV writeheader(WAVt x)
{
  WAV t;
  for(int i=0; i<4; i++) t.ChunkID[i]=x.ChunkID[i];
  lew(t.ChunkSize, x.ChunkSize, 4);
  for(int i=0; i<4; i++) t.Format[i]=x.Format[i];
  for(int i=0; i<4; i++) t.Subchunk1ID[i]=x.Subchunk1ID[i];
  lew(t.Subchunk1Size, x.Subchunk1Size, 4);
  lew(t.AudioFormat, x.AudioFormat, 2);
  lew(t.NumChannels, x.NumChannels, 2);
  lew(t.SampleRate, x.SampleRate, 4);
  lew(t.ByteRate, x.ByteRate, 4);
  lew(t.BlockAlign, x.BlockAlign, 2);
  lew(t.BitsPerSample, x.BitsPerSample, 2);
  for(int i=0; i<4; i++) t.Subchunk2ID[i]=x.Subchunk2ID[i];
  lew(t.Subchunk2Size, x.Subchunk2Size, 4);
  return t;
}
int main()
{
  WAV head;
  WAVt headt={
    //*:little endian
    'R','I','F','F', //byte ChunkID[4];//"RIFF"
    0,               //ChunkSize;      //*
    'W','A','V','E', //Format[4];      //"WAVE"
    'f','m','t',' ', //Subchunk1ID[4]; //"fmt "
    16,              //Subchunk1Size;  //*
    1,               //AudioFormat;    //*, 1:pcm(pulse code modulation)
    2,               //NumChannels;    //*, 1:mono, 2:stereo
    44100,           //SampleRate;     //*
    176400,          //ByteRate;       //*
    4,               //BlockAlign;     //*
    16,              //BitsPerSample;  //*
    'd','a','t','a', //Subchunk2ID[4]; //"data"
    0                //Subchunk2Size;  //*
  };
  scan();
  headt.Subchunk2Size = headt.ByteRate*duration/1000.0;
  headt.ChunkSize = headt.Subchunk2Size+36;
  char filename[40];
  sprintf(filename, "%.fHz Fourier %d times.wav", frequency,Fourier);
  FILE *fp1=fopen(filename,"wb");
  head=writeheader(headt);
  fwrite(&head, sizeof(head), 1, fp1);
  n=(headt.Subchunk2Size)/headt.BlockAlign;
  int ch=headt.NumChannels;
  int size=headt.BlockAlign/ch;
  byte buffer[4];
  phase=(double)0;
  goFourier(frequency,Fourier);

  for(int i=0;i<=n-1;i+=1)
  {
      goHz(i,i+1,a[i]);
  }

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<ch; j++)
    {
      lew(buffer, pcm[i][j], size);
      fwrite(buffer, size, 1, fp1);
    }
  }

  printf("%.2fHz, %.2fsec wav, %dtimes Fourier file generated!!\n", frequency, duration/1000.0,Fourier);
  return 0;
}
