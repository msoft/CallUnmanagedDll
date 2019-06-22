using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace NativeCodeCaller
{
	class Program
	{
		static void Main(string[] args)
		{
			string textToDisplay = "text to display éèà";

			Console.WriteLine($"Displaying from managed code: {textToDisplay}");
			//DllImportExample.DisplayTextWithCallee(textToDisplay);

			string returnedString = string.Empty;

			unsafe
			{
				char* unmanagedString = stackalloc char[textToDisplay.Length + 1];
				IntPtr unmanagedStringPtr = (IntPtr)unmanagedString;
				DllImportExample.DisplayTextWithCalleeAndReturnCopy(textToDisplay, unmanagedStringPtr);
				returnedString = Marshal.PtrToStringUni(unmanagedStringPtr);

				//fixed (char* unmanagedString = new char[textToDisplay.Length + 1])
				//{
				//	IntPtr unmanagedStringPtr = (IntPtr)unmanagedString;
				//	DllImportExample.DisplayTextWithCalleeAndReturnCopy(textToDisplay, unmanagedStringPtr);
				//	returnedString = Marshal.PtrToStringUni(unmanagedStringPtr);
				//}
			}

			Console.WriteLine($"Returned string: {returnedString}");

			Console.ReadLine();
		}
	}

	public class DllImportExample
	{
		[DllImport("NativeCallee.dll", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
		public extern static void DisplayTextWithCallee(string textToDisplay);

		[DllImport("NativeCallee.dll", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
		public extern static void DisplayTextWithCalleeAndReturnCopy(string textToDisplay, IntPtr returnedString);
	}
}
