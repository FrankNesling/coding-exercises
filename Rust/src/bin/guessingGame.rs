use std::io;
use std::cmp::Ordering;

use rand::Rng;

fn main() {
	println!("Guess the number between 1 and 100!");

	let secret_number = rand::thread_rng().gen_range(1..=100);

	// input
	loop {
		println!("Please input your guess!");
		let mut guess = String::new();		// mutable, without mut -> immutable
		io::stdin().read_line(&mut guess).expect("Failed to read this line :(");	// without import -> std::io

		// convert input to number
		let guess: u32 = match guess.trim().parse() {
			Ok(num) => num,
            Err(_) => {
				println!("That is not a number, smartass!");
				continue;
			}
		};

		// check if guess is greate than 100
		match guess.cmp(&100) {
			Ordering::Greater => {
				println!("THe secret is not greater than 100!");
				continue;
			}
			_ => {}
		}


		match guess.cmp(&secret_number) {
			Ordering::Less => println!("No, the secret is bigger"),
			Ordering::Greater => println!("No, the secret is smaller"),
			Ordering::Equal => {
				println!("Good job!");
				break;
			}
		}
	}


	println!("You guessed {secret_number} correctly.");
}