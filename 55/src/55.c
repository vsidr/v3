// Программа: Калькулятор
// Автор: Сидоров Владислав
// Лицензия: GPL v3
// Применение: пользователь выбирает операцию из шести предложенных, затем вводит числа, после чего получает новое значение
// Операции: умножение(*),деление(/),сложение(+),вычитание(-),возведение в степень(^),факториал(!),работа с векторами(v)
// При работе с векторами доступно: сложение, вычитание, скалярное произведение
#include <stdlib.h> // Подключение библиотек
#include <stdio.h> // Подключение библиотек
int main(int argc,char *argv[])
{
    // Здравствуйте!
    // Вас приветствует программа "Калькулятор"!
    // Программа проводит операцию над двумя выбранными Вами числами(векторами) и выводит получившееся значение в файле.
    // Возможные операции: умножение(*),деление(/),сложение(+),вычитание(-),возведение в степень(^),факториал(!),вектора(v).
    // При работе с векторами доступно: сложение, вычитание, скалярное произведение.
    // При неправильном вводе данных программа завершит работу!

	// Порядок ввода в файл(input.txt):
	// Все данные вводятся через пробел! Пример(+ 1 2). В результате получите: 1 + 2 = 3
	// Вектора - (v, размер векторов, значение первого вектора, значение второго вектора, знак операции)
	// Сложение - (+, первое число, второе число)
	// Вычитание - (-, первое число, второе число)
	// Умножение - (*, первое число, второе число)
	// Деление - (/, первое число, второе число)
	// Факториал - (!, число)
	// Возыедение в степень - (^, первое число, второе число)

	// Переменные
    double number1,number2; // 1 и 2 число
    double result; // Результат проведения операции над 1 и 2 числом
    char operation; // Операция
    char consent; // Согласие/отказ дальше работать с программой
    // Переменные для работы с векторами
    double *A,*B; // Первый вектор, второй вектор
    int size;
    char op; // Операция над векторами
    double res; // Результат проведения операции над векторами

    do // Цикл если пользователь захочет продолжить работу с программой
    {
    	// Для корректного вывода
    	setvbuf(stdout, NULL, _IONBF, 0);
    	setvbuf(stderr, NULL, _IONBF, 0);
    	// Файловый ввод - вывод
    	FILE *input, *output;
    	char input_name[259], output_name[259];
    	//Переменные для записи имени файлов
    	printf("Введите название файла формата '.txt', из которого я буду брать данные:");
    	scanf("%s", input_name);
    	printf("Введите название файла формата '.txt', в который я запишу результаты:");
    	scanf("%s", output_name);
    	input = fopen(input_name,"r");
    	output = fopen(output_name,"w");
    	while(fscanf(input, " %c", &operation) != EOF){
        // Операции
        switch(operation)
        {
        // Работа с векторами
            case 'v':
            fscanf(input,"%i",&size); // Введите размер векторов
            A = malloc(size*sizeof(double));
            B = malloc(size*sizeof(double));
            for(int i=0;i<size;i++) fscanf(input,"%lf",&A[i]); // Координаты первого вектора
            for(int i=0;i<size;i++) fscanf(input,"%lf",&B[i]); // Координаты второго вектора
            fscanf(input," %c",&op); // Выбор операции
            if (op == '+')
            {
                // сложение векторов
            	fprintf(output, "(");
            	for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]);
            	fprintf(output, ") + (");
                for(int i=0;i<size;i++) fprintf(output,"%lf ",B[i]);
            	fprintf(output, ") = (");
            	for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]+B[i]);
            	fprintf(output, ")\n");
            }
            if (op == '-')
            {
                // вычитание векторов
            	fprintf(output, "(");
            	for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]);
            	fprintf(output, ") - (");
            	for(int i=0;i<size;i++) fprintf(output,"%lf ",B[i]);
                fprintf(output, ") = (");
                for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]-B[i]);
            	fprintf(output, ")\n");
            }
            if (op == '*')
            {
                // скалярное произведение векторов
            	for(int i=0;i<size;i++) res += A[i]*B[i];
            	fprintf(output, "(");
                for(int i=0;i<size;i++) fprintf(output,"%lf ",A[i]);
            	fprintf(output, ") * (");
                for(int i=0;i<size;i++) fprintf(output,"%lf ",B[i]);
            	fprintf(output, ") = ");
                fprintf(output,"%lf\n",res);
            }
            free(A);
            free(B);
        break;
        // Факториал числа
            case '!':
            fscanf(input," %lf",&number1); // Введите число
            double h = 1;
            double b;
            b = number1;
            if (number1 > 0) for(h = 1; h < b; h++)
            {
                number1 = number1 * (b - h);
            }
            if (number1 == 0) fprintf(output,"0! = 1");
            else if (number1 < 0) fprintf(output,"Факториал отрицательного числа не вычисляется");
            else fprintf(output,"\n%lf! = %lf",b,number1);
        break;
        // Сложение
            case '+':
            fscanf(input," %lf",&number1); // Ввелите первое число
            fscanf(input," %lf",&number2); // Введите второе число
            result = number1 + number2;
            fprintf(output,"\n%lf + %lf = %lf",number1,number2,result);
        break;
        // Вычитание
            case '-':
            fscanf(input," %lf",&number1); // Введите первое число
            fscanf(input," %lf",&number2); // Введите второе число
            result = number1 - number2;
            fprintf(output,"\n%lf - %lf = %lf",number1,number2,result);
        break;
        // Умножение
            case '*':
            fscanf(input," %lf",&number1); // Введите первое число
            fscanf(input," %lf",&number2); // Введите второе число
            result = number1 * number2;
            fprintf(output,"\n%lf * %lf = %lf",number1,number2,result);
        break;
        // Деление
            case '/':
            fscanf(input," %lf",&number1); // Введите первое число
            fscanf(input," %lf",&number2); // Введите второе число
            result = number1 / number2;
            if (number2 == 0) fprintf(output,"Делить на ноль нельзя!");
            else fprintf(output,"\n%lf / %lf = %lf",number1,number2,result);
        break;
        // Возведение в степень
            case '^':
            fscanf(input," %lf",&number1); // Введите первое число
            fscanf(input," %lf",&number2); // Введите второе число(Положительное)
            double a = 1;
            double copy = number1;
            for(a = 1; a < number2; a++)
            {
                number1 = number1 * copy;
                result = number1;
            }
            if (number2 < 0) fprintf(output,"Калькулятор считает только положительные степени!");
            else if (number2 == 0) fprintf(output,"Любое число в степени 0 равно 1");
            else fprintf(output,"\n%lf ^ %lf = %lf",copy,number2,result);
        break;
        // При ошибочном введении операции
        default:
        fprintf(output,"\nВы неправильно выбрали операцию!");
        }
        fclose(input);
        fclose(output);
        // Согласие/отказ дальше работать с программой
        // При y - работа программы продолжится, при n - программа прекратит работу!
        printf("Хотите ли продолжить работу с программой(y/n)?: ");
        scanf(" %c",&consent);
        }
    }while(consent == 'y'); // Условие при котором работа с программой продолжится
    printf("Спасибо за работу! До свидания!");
    return 0;
}
