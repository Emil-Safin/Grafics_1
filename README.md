   ``` c++
    #include "GL/glew.h"                                                                                                                                              
    #include "GL/freeglut.h"                                                                                                                                           
    #include <stdio.h>                                                                                                                                                 
    #include <stdlib.h>                                                                                                                                                 
    #include "GL/glut.h"                                                                                                                                           
    #include "glm/vec2.hpp"                                                                                                                                             
    #include <glm/glm.hpp>
    using namespace glm;                                                                                                                                                

    GLuint VBO; // переменная для хранения указателя на буфер вершин  //

    void Display(void)                                                                                                                                                     
    {

        glClear(GL_COLOR_BUFFER_BIT);  // очищает буфер цвета    
        glClearColor(0.9f, 0.5f, 0.5f, 0.0f); // цвет    
        glEnableVertexAttribArray(0); // индексация                                                                                                                         
        glBindBuffer(GL_ARRAY_BUFFER, VBO); // привязываем буфер для приготавливания его для отрисовки                                                                     
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // как воспринимать данные внутри буфера(шейдеры, кол-во компонентов, тип данных, нормализация атрибута)     
        glDrawArrays(GL_TRIANGLES, 0, 3); // рисуем все(1 параментр указали тип как точку, это значит, что каждая вершина - одна точка, следующий параметр это индекс первой вершины для отрисовки, последний параметр - количество вершин для отрисовки)                                                                                     
        glDisableVertexAttribArray(0); // отключение индексации                                                                                                             
        glutSwapBuffers();// смена буфера                                                                                                                                   

    }
    int main(int argc, char* argv[]) { 

        glutInit(&argc, argv);// инициализируем glut, параметры могут быть переданы прямо из командной строки и включают полезные опции                                    
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // включение двойной буферизации и буфера цвета(GLUT_DOUBLE включает двойную буферизацию, GLUT_RGBA буфер цвета)     
        glutInitWindowSize(1024, 768);                                                                                                                                     
        glutInitWindowPosition(100, 100);                                                                                                                                   
        glutCreateWindow("Tutorial 01");                                                                                                                                   
        glutDisplayFunc(Display);  // регулярно вызывает рендер сцену, эта функция регулярно вызывается GLUT'ом                                                             
        //glutDisplayFunc();                                                                                                                                               
        GLenum res = glewInit(); // инициализируем GLEW и проверяем на ошибки                                                                                               
        if (res != GLEW_OK)                                                                                                                                                 
        {
            fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));                                                                                                     
            return 1;                                                                                                                                                       
        }
        vec3 Vertices[3]; // задаем массив и объявляем xyz                                                                                                                 
        Vertices[0] = vec3(1.0f, 1.0f, 0.0f);                                                                                                                               
        Vertices[1] = vec3(-1.0f, 0.0f, 0.0f);                                                                                                                            
        Vertices[2] = vec3(1.0f, -1.0f, 0.0f);                                                                                                                             
        glGenBuffers(1, &VBO); // создание буфера для помещения объектов (часто принимает 2 параметра: первый определяет количество объектов, которые вы хотите создать, и второй ссылка на массив типа GLuints для хранения указателя, по которому будут храниться данные)                                                                       
        glBindBuffer(GL_ARRAY_BUFFER, VBO);                                                                                                                               
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);  // наполняем данными                                                                   
        glutMainLoop();// цикл вызывающий дисплей фанк, чтобы дать ей возможность нарисовать кадр (GLUT будет вызывать только функцию отображения на экран) 
    }
```





26.03.2022 это был прекрасный солнечный день, сегодня мне исполняется 20 лет - юбилей. Дома меня ждут близкие мне люди, шашлык, тортик, подарки... Однако я нахожусь в вузе на лабораторной по компьютерной графике - грустный и без тортика. Как так все произошло? Почему я в вузе без возможности поехать домой ведь сегодня суббота? - спросите вы меня(в Уфе я живу в общежитии)...

3 дня назад:
Это был пасмурный день, но теплый, изредка выглядывало солнце, лучи которого мягко ложились на мой письменный стол. В эти моменты комната начинала играть новыми, казалось, что не виданными ранее, цветами. За окном пели птицы, а я предвкушал свою поездку домой, которая должна была состояться через три дня. Обычно я очень редко езжу домой, это затратно и редко, когда бывает хороший повод, однако в этот раз повод был! - старшому сыну\внуку семьи исполняется 20 лет, говорят, что совершеннолетним становятся в 18-ть лет, хотя я думаю, что это наступает как раз таки в 20-ть, да и что за число такое 18 ?
Как вдруг мои размышления прервал звук телефонного сообщения. Что бы это могло быть ? - подумал я - Реклама, уведомление, а если же сообщение, то от кого ? Легким движением жмякнув на экран, с удивлением я обнаружил иконку сообщения из социальной сети. Странно, обычно в это время друзья мне не пишут из-за своего необычного графика сна, а на беседах отключены уведомления... - размышлял я. Как вдруг меня осенило, что есть беседа в которой уведомления включены - это "Важное". Что-то написал профорг или же староста... Собравшись с духом я включил телефон, меня обдало холодным потом, сообщение и вправду пришло из беседы "Важное". Да что там может быть такого плохого? - успокаивал я себя. Однако дрож не проходила, трясущимся пальцем я нажал на сообщение дабы развернуть его. Словно предчувствуя беду солнце снова скрылось за облаками, а птицы умолкли. Комната наполнилась тьмой. Не слышно было ни птиц, ни соседей, ни вечно громких арабов. В сообщении говорилось, что в субботу мы будем учиться до поздна, и на эти пары нельзя не прийти... Что-то сломалось во мне в тот момент, было такое ощущение, что из меня вынули кусочек души и растоптали его... Следующие два дня прошли будто состоянии некой полудремы, не было абсолютно никаких чувств, кроме чувства надвигающейся неизбежности.

Так я здесь и оказался, на лабораторной по компьютерной графике. В этот день я научился:
- основам программирования на OpenGL;
- создавать окно;
- базовым функциям;
- научился делать простейшие фигуры(точка, треугольник, многоугольник);
- разобрался в каждой функции, благодаря преподавателю* и одногруппникам.

Да, это все неоценимо и полезно, но стоило ли оно того в действительности, неужели я бы не мог сам этого проделать дома... - думал я, возвращаясь с пары в восемь часов вечера в свой день рождения с чувством опустошения в душе. Что ж, как говорил Г. В. Лейбниц: Что ни делается, все к лучшему. С этой мыслью, и легкой грустью в сердце, я закончу свой монолог.
 * - он нас заставил. 
