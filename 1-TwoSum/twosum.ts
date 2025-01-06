// tsc twosum.ts --outDir bin --outFile twosumts.js     (this is not putting it  in bin)


function twoSum(nums: number[], target: number): number[] | null {
    for (let x = 0; x < nums.length; x++) {
        for (let y = x + 1; y < nums.length; y++) {
            if ((nums[x] + nums[y]) === target) {
                console.log(`${x},${y} equals target ${target}`)
                return [ x, y ];
            }
        }
    }
    return null;
};

function twoSumHash(nums: number[], target: number): number[] | null {
    let map: { [key: number]: number } = {};

    for (let i = 0; i < nums.length; i ++) {
        let temp = target - nums[i];
        if (map.hasOwnProperty(temp)) {
            console.log(`${i},${map[temp]} equals target ${target}`)
            return [i, map[temp]];
        }
        map[nums[i]] = i;
    }
    return null;
}

twoSumHash([2, 7, 11, 15], 9)
twoSumHash([3, 2, 4], 6)
twoSumHash([3, 3], 6)


// Wait... I prefer types but the TS type system is kinda ugly