package codekata;

public class StringAdd {
	public String addString(String left, String right) {
		return addString(left, right, 1, 0, "");
	}
	
	private int getNum(String s, int index) {
		if (index > s.length()) {
			return 0;
		}
		return s.charAt(s.length() - index) - '0';
	}
	
	private String addString(String left, String right, int index, int p,
			String res) {
		if (index > left.length() && index > right.length()) {
			return p > 0 ? String.valueOf(p) + res : res;
		}

		int leftBit = getNum(left, index);
		int rightBit = getNum(right, index);
		int sum = leftBit + rightBit + p;
		res = String.valueOf(sum % 10) + res;
		p = sum >= 10 ? 1 : 0;
		return addString(left, right, index + 1, p, res);
	}
}
