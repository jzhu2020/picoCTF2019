
void main(void)

{
  FILE *flag;
  FILE *picture;
  size_t sVar1;
  long in_FS_OFFSET;
  int i;
  int j;
  char array [4];
  char local_34;
  char local_33;
  char local_29;
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  flag = fopen("flag.txt","r");
  picture = fopen("mystery.png","a");
  if (flag == (FILE *)0x0) {
    puts("No flag found, please make sure this is run on the server");
  }
  if (picture == (FILE *)0x0) {
    puts("mystery.png is missing, please run this on the server");
  }
  sVar1 = fread(array,0x1a,1,flag);
  if ((int)sVar1 < 1) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  puts("at insert");
  
  // 70 69 63 6F 43 54 4B 80 6B 35 7A 73 69 64 36 71 5F 34 65 38 65 36 33 61 37 7D
  // picoCTKk5zsid6q_4e8e63a7}
  // picoCTK.k5zsid6q_4e8e63a7}
  // picoCTF{f0und_1b4e8e63a7}
  fputc((int)array[0],picture);
  fputc((int)array[1],picture);
  fputc((int)array[2],picture);
  fputc((int)array[3],picture);
  fputc((int)local_34,picture);
  fputc((int)local_33,picture);
  i = 6;
  while (i < 0xf) {
    fputc((int)(char)(array[i] + '\x05'),picture);
    i = i + 1;
  }
  fputc((int)(char)(local_29 + -3),picture);
  j = 0x10;
  while (j < 0x1a) {
    fputc((int)array[j],picture);
    j = j + 1;
  }
  fclose(picture);
  fclose(flag);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}
