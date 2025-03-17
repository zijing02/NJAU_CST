public class Instruction {
    private int id;
    private int state;

    public Instruction(int id, int state) {
        this.id = id;
        this.state = state;
    }

    public int getId() {
        return id;
    }

    public int getState() {
        return state;
    }
}