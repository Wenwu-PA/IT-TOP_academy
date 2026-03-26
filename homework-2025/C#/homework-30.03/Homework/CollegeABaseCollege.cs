using System;
using System.Collections.Generic;
using System.Text;
using Common;

namespace CollegeA
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
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Колледж: {CollegeName}");
            sb.Append("Базовые предметы: ");
            sb.AppendLine(string.Join(", ", BaseSubjects));
            return sb.ToString();
        }
    }
}