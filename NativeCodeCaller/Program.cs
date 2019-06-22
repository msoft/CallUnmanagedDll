using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using MixedAssembly;

namespace NativeCodeCaller
{
	class Program
	{
		static void Main(string[] args)
		{
			string textToDisplay = "text to display éèà";

			Console.WriteLine($"Displaying from managed code: {textToDisplay}");

			NativeCaller nativeCaller = new NativeCaller(textToDisplay);
			nativeCaller.CallNativeCode();

			Console.ReadLine();
		}
	}
}
