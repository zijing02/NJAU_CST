public class Instruction {
    private int id;
    private int state;

    public Instruction(int id, int state) {
        this.id = id;
        this.state = state;
    }

    public int GetId() {
        return id;
    }

    public int GetState() {
        return state;
    }
}