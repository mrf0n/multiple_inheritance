# Множественное наследование, управление памятью
Разработать консольное приложение позволяющее вводить/выводить/удалять информацию о кухонной утвари. Приложение должно удовлетворять следующим требованиям:

1.Содержать иерархию классов

  1.1 Абстрактный класс «Кухонная утварь»
  
      Поля:
      Инвентарный номер
      
  1.2 Класс «Плита», наследуется от «Кухонная утварь»
  
      Поля:
      Цвет
      
  1.3 Класс «Кастрюля», наследуется от «Кухонная утварь»
  
      Поля:
      Объем
      
  1.4 Класс «Плита электрическая», наследуется от «Плита»
  
      Поля:
      Мощность
      
  1.5 Класс «Плита газовая», наследуется от «Плита»
  
      Поля:
      Расход газа
      
  1.6 Класс «Мультиварка», наследуется от «Плита электрическая» и «Кастрюля»
  
      Поля:
      Имеет ли функцию скороварки
      
2.Объекты хранить в динамической структуре в виде упорядоченного бинарного дерева. В качестве ключа для помещения объекта в дерево использовать инвентарный номер. 

3.Реализовать возможность

  3.1 Ввода данных
  
        Тип кухонной утвари
        Инвентарный номер
        Поля, соответствующие конкретной утвари
        При попытке добавления объекта с инвентарным номером, уже присутствующим в дереве, выдавать соответствующее сообщение и выводить информацию о найденном объекте.
        
  3.2 Удаления данных (по инвентарному номеру)
  
  3.3 Вывода данных (прямой, обратный, симметричный обходы дерева)
  
4.Для вывода данных реализовать метод print() в каждом классе. При этом метод класса должен печатать только внутренние поля класса + вызывать метод print() классов-родителей.
