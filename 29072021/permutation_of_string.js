
const permutation = (str, prefix) => {
	if (str.length === 0) {
		console.log(prefix);
		return;
	}

	for (let i = 0; i < str.length; i++) {
		const rem = str.slice(0, i) + str.slice(i + 1);
		permutation(rem, prefix + str.charAt(i));
	}
}


permutation('abcd','')