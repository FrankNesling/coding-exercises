use rand::Rng;
use std::io::{self, Write};
use std::time::Instant;
use std::{thread, time::Duration};

fn check_enter() -> bool {
    let mut input = String::new();
    io::stdout().flush().unwrap();

    io::stdin().read_line(&mut input).expect("Failed to read line");

    input.trim().is_empty()	// <-- return, last line an no semicolon
}


fn main() {
	println!("How fast is your reaaction time?");
	let reaction_wait = rand::thread_rng().gen_range(2..=5);

	println!("After the start, there will be a signal after a few seconds and you have to press Enter as quickly as possible.");
	println!("Are you ready? Press Enter!");

	if check_enter() {
		// sleep
		thread::sleep(Duration::from_secs(reaction_wait)); 

		
		// reaction test
		println!("\n\n\nGO GO GO ");
		let start = Instant::now();
		if check_enter() {
			let elapsed = start.elapsed();
			println!("Your reaction: {:?}", elapsed);
		} else {
			println!("Wrong button!");
		}
	} else {
		println!("OK! Then not, bye!");
	}

}



