
void FUN_001010d0(unsigned int param_1,long long param_2,long long param_3)

{
  long lVar1;
  
  _DT_INIT();
  lVar1 = 0;
  do {
    (*(code *)(&__DT_INIT_ARRAY)[lVar1])((unsigned long)param_1,param_2,param_3);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 1);
  return;
}


void print_menu(void)

{
  puts("1. New page in diary");
  puts("2. Talk with ghost");
  puts("3. Listen to ghost");
  puts("4. Burn the page");
  puts("5. Go to sleep");
  printf("> ");
  return;
}



void listen_to_ghost(void)

{
  long in_FS_OFFSET;
  unsigned int local_14;
  //long local_10;
  
  //local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Page: ");
  scanf("%d",&local_14);
  printf("Content: ");
  if ((local_14 < 0x14) && (*(long *)(&diary + (unsigned long)local_14 * 0x10) != 0)) {
    puts(*(char **)(&diary + (unsigned long)local_14 * 0x10));
  }
  /*if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }*/
  return;
}


void talk_with_ghost(void)

{
  long lVar1;
  long in_FS_OFFSET;
  unsigned int local_14;
  
  //lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Page: ");
  scanf("%d");
  printf("Content: ");
  if ((local_14 < 0x14) && (*(long *)(&diary + (unsigned long)local_14 * 0x10) != 0)) {
    FUN_00100a5a(*(long *)(&diary + (unsigned long)local_14 * 0x10),
                 *(unsigned int *)(&DAT_00302068 + (unsigned long)local_14 * 0x10));
  }
  /*if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
    __stack_chk_fail();
  }*/
  return;
}


void new_page(void)

{
  void *pvVar1;
  long in_FS_OFFSET;
  unsigned int local_1c;
  int local_18;
  unsigned int local_14;
  //long local_10;
  
  //local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_14 = 0;
  while ((local_14 < 0x14 && (*(long *)(&diary + (unsigned long)local_14 * 0x10) != 0))) {
    local_14 = local_14 + 1;
  }
  if (local_14 == 0x14) {
    puts("Buy new book");
  }
  else {
    puts("1. Write on one side?");
    puts("2. Write on both sides?");
    while( true ) {
      while( true ) {
        while( true ) {
          printf("> ");
          scanf("%d",&local_18);
          if (local_18 != 1) break;
          printf("size: ");
          scanf("%d",&local_1c);
          if (local_1c < 0xf1) goto LAB_00100c64;
          puts("too big to fit in a page");
        }
        if (local_18 != 2) goto LAB_00100ce5;
        printf("size: ");
        scanf("%d",&local_1c);
        if (0x10f < local_1c) break;
        puts("don\'t waste pages -_-");
      }
      if (local_1c < 0x1e1) break;
      puts("can you not write that much?");
    }
LAB_00100c64:
    pvVar1 = malloc((unsigned long)local_1c);
    *(void **)(&diary + (unsigned long)local_14 * 0x10) = pvVar1;
    if (*(long *)(&diary + (unsigned long)local_14 * 0x10) == 0) {
      puts("oh noooooooo!! :(");
    }
    else {
      *(unsigned int *)(&DAT_00302068 + (unsigned long)local_14 * 0x10) = local_1c;
      printf("page #%d\n",(unsigned long)local_14);
    }
  }
LAB_00100ce5:
  //if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  //}
                    /* WARNING: Subroutine does not return */
  //__stack_chk_fail();
}


void FUN_00100a5a(long param_1,unsigned int param_2)

{
  ssize_t sVar1;
  long in_FS_OFFSET;
  char local_15;
  unsigned int local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_14 = 0;
  if (param_2 != 0) {
    while (local_14 != param_2) {
      sVar1 = read(0,&local_15,1);
      if (sVar1 != 1) {
        puts("read error");
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      if (local_15 == '\n') break;
      *(char *)((unsigned long)local_14 + param_1) = local_15;
      local_14 = local_14 + 1;
    }
    *(undefined *)(param_1 + (unsigned long)local_14) = 0;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void _FINI_0(void)

{
  if (DAT_00302048 != '\0') {
    return;
  }
  __cxa_finalize(PTR_LOOP_00302008);
  FUN_00100980();
  DAT_00302048 = 1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x00100997) */
/* WARNING: Removing unreachable block (ram,0x001009a3) */

void FUN_00100980(void)

{
  return;
}


void entry(long long param_1,long long param_2,long long param_3)

{
  long long in_stack_00000000;
  undefined auStack8 [8];
  
  __libc_start_main(run_diary,in_stack_00000000,&stack0x00000008,FUN_001010d0,FUN_00101140,
                    param_3,auStack8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}




long long run_diary(void)

{
  int iVar1;
  //long in_FS_OFFSET;
  undefined4 local_14;
  long local_10;
  
  //local_10 = *(long *)(in_FS_OFFSET + 0x28);
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  alarm(0x3c);
  signal(0xe,FUN_00100f72);
  puts("-=-=-=[[Ghost Diary]]=-=-=-");
  do {
    print_menu();
    scanf("%d",&local_14);
    do {
      iVar1 = getchar();
    } while (iVar1 != 10);
    switch(local_14) {
    default:
      puts("Invalid choice");
      break;
    case 1:
      new_page();
      break;
    case 2:
      talk_with_ghost();
      break;
    case 3:
      listen_to_ghost();
      break;
    case 4:
      burn_page();
      break;
    case 5:
      puts("bye human!");
      /*if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
      }*/
      return 0;
    }
  } while( true );
}


