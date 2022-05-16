/**
 * 大顶堆
 */
public class MaximumHeap {
    private int[] data;
    private int capacity;

    public MaximumHeap(int[] data) {
        this.data = data;
        this.capacity = data.length;
    }

    public void sort() {
        for (int i = capacity/2 - 1; i >= 0; i--) {
            // 初始化堆，初始化完成后，堆顶为最大值
            heaptify(data, data.length, i);
        }

        for (int i = data.length - 1; i >=0; i--) {
            // 将堆顶的最大值交换至数组末尾，调整堆
            int tmp = data[i];
            data[i] = data[0];
            data[0] = tmp;

            heaptify(data, i, 0);
        }
    }

    private void heaptify(int[] data, int n, int root) {
        int l = root * 2 + 1;
        int r = root * 2 + 2;
        int largest = root;

        if (l < n && data[l] > data[largest]) {
            // 若左子节点大于最大节点，交换
            largest = l;
        }

        if (r < n && data[r] > data[largest]) {
            // 若右子节点大于最大节点，交换
            largest = r;
        }

        if (root != largest) {
            // 若最大值不是根节点，交换
            int tmp = data[root];
            data[root] = data[largest];
            data[largest] = tmp;

            heaptify(data, n, largest);
        }
    }

    public void print() {
        for(int i = 0; i < capacity; i++) {
            System.out.printf("%d ", data[i]);
        }
        System.out.println();
    }
}
