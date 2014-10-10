package codekata;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class StringAddTest {
	private StringAdd stringAdd;

	@Before
	public void setUp() throws Exception {
		this.stringAdd = new StringAdd();
	}

	@Test
	public void test() {
		assertEquals("1", stringAdd.addString("1", "0"));
		assertEquals("11", stringAdd.addString("9", "2"));
		assertEquals("13", stringAdd.addString("11", "2"));
		assertEquals("200", stringAdd.addString("101", "99"));
		assertEquals("199", stringAdd.addString("100", "99"));
		assertEquals("1000000", stringAdd.addString("999999", "1"));
	}

}
