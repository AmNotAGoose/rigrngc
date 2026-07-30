int roll_dice(int size) {
	return (rand() % size) + 1;
}

int scrapyard() {
	return roll_dice(6) + roll_dice(6);
}
