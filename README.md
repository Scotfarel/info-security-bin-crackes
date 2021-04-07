## Zakharov Ivan, Variant 20


### crackme1.exe

1. В IDA находим чуть выше фразы *"Wrong code"* ф-ю *"CMP"*.
![img.png](screens/1-0.png?raw=true)
 
   Отправляемся на ее код: *"0401665"* в дебаггер.
Подглядываем в дебаггере, что для имени *"a"* программа генерит пароль *"48307574"*.
   ![img_1.png](screens/1-1.png?raw=true)
 
   Проверяем запуск:
   
   ![img_2.png](screens/1-2.png?raw=true)
   
2. В IDA в том же месте видим переход на ветку *"Wrong code"*.
   ![2-0.png](screens/2_0.jpg?raw=true)

    Патчим его:
    - До:
   ![2-1.png](screens/2_1.png?raw=true)
    - После:
![2-2.png](screens/2_2.png?raw=true)

3. В IDA используем декомпайлер и получаем из ассемблерного выхлопа псевдокод:

   ```
   char v2; // [esp+6h] [ebp-1Ah]
   char v3; // [esp+17h] [ebp-9h]
   char *i; // [esp+18h] [ebp-8h]
   signed int v5; // [esp+1Ch] [ebp-4h]

   v5 = 0x455FAD;
   for ( i = username; *i; ++i )
   {   
       v2 = *i;
       if ( *i <= 109 )
           v3 = v2 ^ 0x13;
       else
           v3 = v2 ^ 0x88;
       v5 += (char)(v3 + 1);
   }
   ```

### crackme2.exe
*Забавно, что crackme2 можно сломать, введя любой юзернейм, а затем введя ЛЮБОЙ пароль(!) длиной меньше четырех, начинающийся с символа переноса строки!*

1. В IDA, листая файл, замечаем *"ok_code"*, *"wrong_code"*. Аналогично первой программе, ф-я *"CMP"*.
   ![3-0.jpg](screens/3_0.jpg?raw=true)
    Подглядываем в дебаггере, что для имени *"a"* программа генерит пароль *"82-18"*.
   ![3-1.jpg](screens/3_1.jpg?raw=true)
   
   Проверяем запуск:
   
   ![3-2.jpg](screens/3_2.jpg?raw=true)

2. В IDA видим дерево ветвлений, вырезаем оба *"jz"*.
   ![4_0.jpg](screens/4_0.jpg?raw=true)
   Патчим:
    - До
      ![4_1.png](screens/4_1.png?raw=true)
   - После
     ![4_2.png](screens/4_2.png?raw=true)
3. Аналогично *crackme1.exe*:
    ```
        char v2[4]; // [esp+10h] [ebp-18h]
        signed int v3; // [esp+14h] [ebp-14h]
        int v4; // [esp+18h] [ebp-10h]
        char *v5; // [esp+1Ch] [ebp-Ch]

        v5 = username;
        v4 = 3;
        v3 = 18;
        v2[2] = 7;
        v2[1] = 31;
        v2[3] = 0;
        while ( *v5 )
        {
            v2[0] = *v5;
            v3 += 16 * v2[3];
            v4 = (v3 - *v5) ^ 0x1F;
            v2[3] = *v5++;
        }
        printf("%u-%u\n", abs(v4), abs(v3));
    ```
