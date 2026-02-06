using System;
using Xunit;
using System.IO;

namespace HelloWorldTests
{
    public class UnitTest1
    {
        private const string Expected = "Hello World!";
        [Fact]
        public void Test1()
        {
            using (var sw = new StringWriter())
            {
                Console.SetOut(sw);
                HelloWorld.Program.Main();

                var result = sw.ToString().Trim();
                Assert.Equal(Expected, result);
            }
        }
    }
}