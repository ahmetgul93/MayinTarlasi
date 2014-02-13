  #include<stdio.h>
  #include<dos.h>
  #include<conio.h>
  #include<graphics.h> 
  #define MOUSE       0x33
  #define BUT1PRESSED  1
  #define BUT2PRESSED  2
  #define TRUE         1
  #define FALSE        0
  void ActivMouse()
  {
        _AX=32;
       geninterrupt(MOUSE);
  }
  int ResetMouse()
  {
         _AX=0;
       geninterrupt(MOUSE);
       return(_AX);
  }
  void ShowMouse()
  {
          _AX=1;
       geninterrupt(MOUSE);
  }
  void HideMouse()
  {
          _AX=2;
       geninterrupt(MOUSE);
  }
  void ReadMouse(int *v,int *h,int *but)
  {
       int temp;
       _AX=3;
       geninterrupt(MOUSE);
       /* hangi butona basildi 1=sol 2=sag, 3=ikisi */
       temp=_BX;
       *but=temp;
     /* yatay kordinat */
       *h =_CX;
     /* düsey kordinat */
       *v=_DX;
  }
