using System;
using System.Collections.Generic;
using System.Text;
using Common;

namespace CollegeB
{
    public class BaseCollege
    {
        public string CollegeName { get; set; }
        public List<CommonSubject> BaseSubjects { get; set; }

        public BaseCollege(string collegeName, List<CommonSubject> baseSubjects)
        {
            CollegeName = collegeName;
            BaseSubjects = baseSubjects ?? new List<CommonSubject>();
        }

        public override string ToString()
        {
            return $"Колледж: {CollegeName}\nБазовые предметы: {string.Join(", ", BaseSubjects)}";
        }
    }
}