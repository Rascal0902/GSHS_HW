int parseFile3(){
  BufferedReader reader10 = createReader("H.txt");String line10 = null;int a10=0;
 try {while ((line10 = reader10.readLine()) != null) {
    data1[a10]=floattry(line10);a10++; 
 }reader10.close();}
 catch (IOException e) {e.printStackTrace();}return 1;}
 float floattry(String str){
  float[] subfloat = new float[2];float ans;//소수점 아래 5자리 까지
  int now=0;subfloat[0]=0;subfloat[1]=0;String[] newfloat = split(str,'.');//println(str);
  for(int i=0;i<2;i++){for(int j=0;j<newfloat[i].length();j++){
      if(newfloat[i].substring(j,j+1).equals("0")==true){now=0;}
      if(newfloat[i].substring(j,j+1).equals("1")==true){now=1;}
      if(newfloat[i].substring(j,j+1).equals("2")==true){now=2;}
      if(newfloat[i].substring(j,j+1).equals("3")==true){now=3;}
      if(newfloat[i].substring(j,j+1).equals("4")==true){now=4;}
      if(newfloat[i].substring(j,j+1).equals("5")==true){now=5;}
      if(newfloat[i].substring(j,j+1).equals("6")==true){now=6;}
      if(newfloat[i].substring(j,j+1).equals("7")==true){now=7;}
      if(newfloat[i].substring(j,j+1).equals("8")==true){now=8;}
      if(newfloat[i].substring(j,j+1).equals("9")==true){now=9;}
      subfloat[i]*=10;subfloat[i]+=now;}}ans=subfloat[0]+subfloat[1]/pow(10,newfloat[1].length());return ans;}
int parseFile4(){
  BufferedReader reader10 = createReader("E.txt");String line10 = null;int a10=0;
 try {while ((line10 = reader10.readLine()) != null) {
   if(a10>800){continue;}
    data1[a10]=floattry(line10);a10++; 
 }reader10.close();}
 catch (IOException e) {e.printStackTrace();}return 1;}
