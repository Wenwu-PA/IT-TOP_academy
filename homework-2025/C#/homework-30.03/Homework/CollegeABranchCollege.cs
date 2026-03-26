using System;
using System.Collections.Generic;
using System.Text;
using Common;

namespace CollegeA
{
    public class BranchCollege : BaseCollege
    {
        public string BranchName { get; set; }
        public List<OptionalSubject> OptionalSubjects { get; set; }

        public BranchCollege(string collegeName, List<CommonSubject> baseSubjects,
                             string branchName, List<OptionalSubject> optionalSubjects)
            : base(collegeName, baseSubjects)
        {
            BranchName = branchName;
            OptionalSubjects = optionalSubjects ?? new List<OptionalSubject>();
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(base.ToString());
            sb.AppendLine($"Филиал: {BranchName}");
            sb.Append("Дополнительные предметы: ");
            sb.AppendLine(string.Join(", ", OptionalSubjects));
            return sb.ToString();
        }
    }
}