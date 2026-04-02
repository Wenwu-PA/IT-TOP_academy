using System;
using System.Collections.Generic;
using Common;
using CollegeA;
using CollegeB;

public static class CollegeTest
{
    public static void Run()
    {
        // Первый колледж (CollegeA)
        var collegeA = new CollegeA.BaseCollege("Колледж информатики", new List<CommonSubject>
        {
            CommonSubject.Математика,
            CommonSubject.Физика,
            CommonSubject.РусскийЯзык
        });

        // Второй колледж (CollegeB)
        var collegeB = new CollegeB.BaseCollege("Колледж гуманитарных наук", new List<CommonSubject>
        {
            CommonSubject.РусскийЯзык,
            CommonSubject.Математика
        });

        // Два филиала первого колледжа
        var branchA1 = new CollegeA.BranchCollege(
            collegeA.CollegeName,
            collegeA.BaseSubjects,
            "Филиал в центре",
            new List<OptionalSubject> { OptionalSubject.Программирование, OptionalSubject.АнглийскийЯзык }
        );

        var branchA2 = new CollegeA.BranchCollege(
            collegeA.CollegeName,
            collegeA.BaseSubjects,
            "Филиал в пригороде",
            new List<OptionalSubject> { OptionalSubject.Физкультура }
        );

        // Два филиала второго колледжа
        var branchB1 = new CollegeB.BranchCollege(
            collegeB.CollegeName,
            collegeB.BaseSubjects,
            "Филиал на севере",
            new List<OptionalSubject> { OptionalSubject.АнглийскийЯзык, OptionalSubject.Программирование }
        );

        var branchB2 = new CollegeB.BranchCollege(
            collegeB.CollegeName,
            collegeB.BaseSubjects,
            "Филиал на юге",
            new List<OptionalSubject> { OptionalSubject.Физкультура, OptionalSubject.АнглийскийЯзык }
        );

        // Вывод информации
        Console.WriteLine("=== Филиалы первого колледжа (CollegeA) ===");
        Console.WriteLine(branchA1);
        Console.WriteLine();
        Console.WriteLine(branchA2);
        Console.WriteLine();

        Console.WriteLine("=== Филиалы второго колледжа (CollegeB) ===");
        Console.WriteLine(branchB1);
        Console.WriteLine();
        Console.WriteLine(branchB2);
    }
}