//yandex task 4. Наибольшее произведение двух чисел
using System;
using System.Collections.Generic;

class Biggest_numbers {
	public long[] positives = new long[2];
	public long[] negatives = new long[2];
	
	public long[] biggest_pair() {
		if (positives[0] * positives[1] > negatives[0] * negatives[1]) {
			Array.Sort(positives);	
			return positives;
		}
		Array.Sort(negatives);	
		return negatives;
	}
	
	public void accomodate_number(long number) {
		if (number > 0) {
			if (this.positives[0] < number) {
				this.positives[1] = this.positives[0];
				this.positives[0] = number;
			} else if (this.positives[1] < number) {
				this.positives[1] = number;
			}
		} else {
			if (this.negatives[0] > number) {
				this.negatives[1] = this.negatives[0];
				this.negatives[0] = number;
			} else if (this.negatives[1] > number) {
				this.negatives[1] = number;
			}
		}
	}
}

class Program
{
    static void Main()
    {
        string text_input = Console.ReadLine();
        string[] text_numbers = text_input.Split(' ');
        List<long> numbers = new();
        foreach(var text_number in text_numbers) {
            numbers.Add(long.Parse(text_number));
        }
		
		var biggest_numbers = get_biggest_numbers(numbers);
		
		Console.WriteLine(string.Join(" ", biggest_numbers.biggest_pair()));
    }
	
	
	
	static Biggest_numbers get_biggest_numbers(List<long> all_numbers) {
		Biggest_numbers result = new Biggest_numbers();
		foreach(long number in all_numbers) {
			result.accomodate_number(number);
			//Console.WriteLine($"result.positives={string.Join(" ", result.positives)} result.negatives={string.Join(" ", result.negatives)}");
		}
		return result;
	}
}
