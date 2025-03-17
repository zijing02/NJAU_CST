public class Device {
    private int totalNumber;

    public Device(int maxCapacity) {
        this.totalNumber = maxCapacity;
    }

    public boolean AbleToAllocate(int need) {
        return totalNumber < need;
    }

    public void Use(int need) {
        totalNumber -= need;
    }

    public void Release(int need) {
        totalNumber += need;
    }

    public int GetTotalNumber() {
        return totalNumber;
    }
}
